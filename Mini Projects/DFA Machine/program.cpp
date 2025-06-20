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
        for (auto state : states)
        {
            if (state.get_name() == name)
                return &state;
        }

        return NULL;
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
                    cout << "Undefined Symbol! " << symbol;
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
    Machine tria("ab");   // * A machine that accepts alphabet {a, b} and always end at triple 'a'

    // ? Add states
    tria.add_state("q0");
}
