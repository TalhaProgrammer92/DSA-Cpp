#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// ? Node / State
class State
{
	// * Attributes
	char name;
	unordered_map<char, pair<State *, int>> transition;

public:
	// * Constructor
	State() {}
	State(char name)
	{
		// ! Assign name
		this->name = name;
	}

	// * Getters
	char get_name()
	{
		return name;
	}

	State *get_state_transition(char symbol)
	{
		return (is_valid_symbol(symbol)) ? transition[symbol].first : NULL;
	}

	int get_direction_transition(char symbol)
	{
		return (is_valid_symbol(symbol)) ? transition[symbol].second : 0;
	}

	// * Setters
	void make_transition(char symbol, State *state, int direction)
	{
		transition[symbol] = {state, direction};
	}

	// * Check if a symbol is valid
	bool is_valid_symbol(char symbol)
	{
		return transition.find(symbol) != transition.end();
	}
};

// ? Tape
class Tape
{
	// * Attributes
	vector<char> tape;
	char blank;
	int head;

public:
	// * Constructors
	Tape() {}
	Tape(string &_string, char blank)
	{
		// ! Assign attributes
		head = 0;
		this->blank = blank;

		for (char symbol : _string)
			tape.push_back(symbol);
	}

	// * Getters
	char get_symbol()
	{
		return (is_blank()) ? blank : tape[head];
	}

	char get_blank()
	{
		return blank;
	}

	// * Setter
	void set_symbol(char symbol)
	{
		tape[head] = symbol;
	}

	// * Check for blank
	bool is_blank()
	{
		// ! If head is out of range
		if (head < 0 || head >= tape.size())
			return false;

		// ! If head pointing to blank
		return tape[head] == blank;
	}
};

int main()
{
}