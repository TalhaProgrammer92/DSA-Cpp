#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ? State Class
class State
{
    // * Attributes
    string name;
    bool is_final;
    unordered_map<char, State *> transition_map;

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

int main()
{
    // ? Create a machine
    Machine m1("ab");   // * A machine that accepts alphabet {a, b} and always end at 'a'

    // ? Add states
    m1.add_state("q0");
    m1.add_state("q1", true);

    // ? Create transitions
    m1.create_transition("q0", "q1", 'a');
    m1.create_transition("q0", "q0", 'b');

    m1.create_transition("q1", "q1", 'a');
    m1.create_transition("q1", "q0", 'b');

    // ? Simulate
    cout << "Simulate: " << m1.simulate("babbaa") << endl;
    cout << "Simulate: " << m1.simulate("babbaab") << endl;
    m1.simulate("abca");
}
