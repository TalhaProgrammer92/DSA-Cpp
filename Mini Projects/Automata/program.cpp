#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ? State Class
class State
{
    // * Attributes
    unordered_map<char, State *> transition_map;
    bool is_final;

protected:
    string name;

public:
    // * Constructors
    State() {} // ! Default

    State(string name, string alphabet, bool is_final)
    {
        // ! Assign values
        this->name = name;
        this->is_final = is_final;

        // ! Create a NULL map form given alphabet
        for (char symbol : alphabet)
            transition_map[symbol] = NULL;
    }

    // * Getters
    string get_name()
    {
        return name;
    }

    bool final_state()
    {
        return is_final;
    }

    // * Check if a symbol is valid
    bool is_valid_symbol(char symbol)
    {
        return transition_map.find(symbol) != transition_map.end();
    }

    // * Create transition on a symbol
    void create_transition(State *state, char symbol)
    {
        // ! Make a transition
        if (is_valid_symbol(symbol))
            transition_map[symbol] = state;
        else
            cout << "The given symbol '" << symbol << "' doesn't exist in the alphabet!" << endl;
    }

    // * Get transition on a symbol
    State *get_transition(char symbol)
    {
        // ! Do a transition
        if (is_valid_symbol(symbol))
            return transition_map[symbol];

        cout << "The given symbol '" << symbol << "' doesn't exist in the alphabet!" << endl;
        return NULL;
    }
};

// ? Machine class - builds DFA
class Machine
{
    // * Attributes
    vector<State> states;

protected:
    string alphabet;

public:
    // * Constructor
    Machine(string alphabet) : alphabet(alphabet) {}

    // * Getters
    int states_count()
    {
        return states.size();
    }

    string get_alphabet()
    {
        return alphabet;
    }

    // * Add a state
    void add_state(string name, bool is_final = false)
    {
        states.push_back(State(name, alphabet, is_final));
    }

    // * Get a state
    State *get_state(string name)
    {
        for (int i = 0; i < states.size(); i++)
        {
            State *state = &states[i];
            if (state->get_name() == name)
                return state;
        }

        return NULL;
    }

    // * Create transition
    void create_transition(string state1, string state2, char symbol)
    {
        get_state(state1)->create_transition(get_state(state2), symbol);
    }

    // * Simulate the machine - check the pattern
    bool simulate(string pattern)
    {
        // ! If states exist
        if (states.size() > 0)
        {
            // ! Get initial state
            State *state = &states[0];

            // ! Treverse the transition path
            for (char symbol : pattern)
            {
                // ! Incorrect pattern - Case undefined symbol
                if (!state->is_valid_symbol(symbol))
                {
                    cout << "Undefined Symbol! " << symbol << endl;
                    return false;
                }

                // ! Do a transition
                state = state->get_transition(symbol);
            }

            // ! Check if ended at final state
            return state->final_state();
        }

        return false;
    }
};

// ? Modulo Machine - Modified version of machine class
class ModuloMachine
{
    // * Attributes
    Machine *machine;

public:
    // * Constructor
    ModuloMachine(string alphabet)
    {
        machine = new Machine(alphabet);
    }

    // * Generator
    void generate_dfa(int value, int target)
    {
        // ! Add states
        for (int i = 0; i < target; i++)
            machine->add_state("r" + to_string(i), i == value);

        // ! Make transitions
        int id = 0;
        for (int i = 0; i < target; i++)
        {
            for (char symbol : machine->get_alphabet())
            {
                // ! Get transition states' names
                string state1, state2;

                state1 = "r" + to_string(i);
                state2 = "r" + to_string(id++);

                // ! Reset id
                if (id == target)
                    id = 0;

                // cout << state1 << ' ' << state2 << ' ' << symbol << endl;   // ! Debug

                // ! Create transition
                machine->create_transition(state1, state2, symbol);
            }
        }
    }

    // * Simulate
    bool simulate(string pattern)
    {
        return machine->simulate(pattern);
    }
};

// ? Special State
class MooreState : public State
{
    // * Attributes
    char output;
    unordered_map<char, MooreState *> transition_map;

public:
    // * Constructors
    MooreState() {}

    MooreState(string name, string alphabet, char output) : State()
    {
        // ! Assigning values
        this->name = name;
        this->output = output;

        // ! Make transitions null
        for (char symbol : alphabet)
            transition_map[symbol] = NULL;
    }

    // * Create transition
    void create_transition(char symbol, MooreState *state)
    {
        if (this->is_valid_symbol(symbol))
            transition_map[symbol] = state;
    }

    // * 
};

// ? Moore Machine
class MooreMachine : Machine
{
    // * Attributes
    vector<MooreState> states;
};

int main()
{
    // // ? Create a machine
    // Machine m1("ab");   // * A machine that accepts alphabet {a, b} and always end at 'a'

    // // ? Add states
    // m1.add_state("q0");
    // m1.add_state("q1", true);

    // // ? Create transitions
    // m1.create_transition("q0", "q1", 'a');
    // m1.create_transition("q0", "q0", 'b');

    // m1.create_transition("q1", "q1", 'a');
    // m1.create_transition("q1", "q0", 'b');

    // // ? Simulate
    // cout << "Simulate: " << m1.simulate("babbaa") << endl;
    // cout << "Simulate: " << m1.simulate("babbaab") << endl;
    // m1.simulate("abca");

    // ? another DFA - {0, 1} where |w| = 3(mod 7)
    // Machine m2("01");

    // m2.add_state("q0");
    // m2.add_state("q1");
    // m2.add_state("q2");
    // m2.add_state("q3", true);   // ! Final state
    // m2.add_state("q4");
    // m2.add_state("q5");
    // m2.add_state("q6");

    // m2.create_transition("q0", "q0", '0');
    // m2.create_transition("q0", "q1", '1');

    // m2.create_transition("q1", "q2", '0');
    // m2.create_transition("q1", "q3", '1');

    // m2.create_transition("q2", "q4", '0');
    // m2.create_transition("q2", "q5", '1');

    // m2.create_transition("q3", "q6", '0');
    // m2.create_transition("q3", "q0", '1');

    // m2.create_transition("q4", "q1", '0');
    // m2.create_transition("q4", "q2", '1');

    // m2.create_transition("q5", "q3", '0');
    // m2.create_transition("q5", "q4", '1');

    // m2.create_transition("q6", "q5", '0');
    // m2.create_transition("q6", "q6", '1');

    // cout << "Simulate: " << m2.simulate("11000") << endl;
    // cout << "Simulate: " << m2.simulate("11001") << endl;

    ModuloMachine m3("01");

    m3.generate_dfa(3, 7);

    cout << "Simulate: " << m3.simulate("11000") << endl;
    cout << "Simulate: " << m3.simulate("11001") << endl;
}
