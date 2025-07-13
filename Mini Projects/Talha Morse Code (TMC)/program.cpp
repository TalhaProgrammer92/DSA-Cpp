#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>

using namespace std;

// ? Key
class Key
{
	// * Attributes
	unordered_map<int, char> symbol_map;
	unordered_map<char, int> number_map;
	int base;

public:
	// * Constructor
	Key(vector<char> symbols)
	{
		base = symbols.size();

		for (int i = 0; i < base; i++)
		{
			char symbol = symbols[i];
			symbol_map[i] = symbol;
			number_map[symbol] = i;
		}
	}

	// * Getters
	int get_base()
	{
		return base;
	}

	char get_number(char symbol)
	{
		return number_map[symbol];
	}

	int get_symbol(int number)
	{
		return symbol_map[number];
	}
};

// ? Parser
class Parser
{
public:
	// * Text -> Morse
	static vector<string> to_morse(string text, Ket &key)
	{
		vector<string> morse;

		return morse;
	}
};

// ? TMC
class TalhaMorseCode
{
public:
	// * Encoder
	static vector<string> encode(string &text, Key &key);

	// * Decoder
	static string decode(vector<string> &code, Key &key);
};

// ? Display TMC
void display(vector<string> &tmc)
{
	for (string t : tmc)
		cout << t << ' ';
	cout << endl;
}

// ? Entry Point
int main()
{
	// Key key({'+', '-', '*', '/', '<', '>', '(', ')', '[', ']'});
	// string text = "The quick brown fox jumps over a lazy dog";
	// vector<string> tmc = TalhaMorseCode::encode(text, key);
	// display(tmc);
	// cout << TalhaMorseCode::decode(tmc, key) << endl;'
}
