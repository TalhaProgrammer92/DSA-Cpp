#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>

using namespace std;

// ? Key
class Key
{
	// * Attributes
	unordered_map<char, char> key;
	int base;

public:
	// * Constructor
	Key(vector<char> symbols)
	{
		base = symbols.size();

		for (int i = 0; i < base; i++)
		{
			key[i + '0'] = symbols[i];
			key[symbols[i]] = i + '0';
		}
	}

	// * Getters
	int get_base()
	{
		return base;
	}

	char get_value(char key)
	{
		return this->key[key];
	}
};

// ? Conversion
class Conversion
{
public:
	// * Number -> Base n
	static string to_base(int number, int base){{string bn = "";

	while (number > 0)
	{
		bn = to_string(number % base) + bn;
		number /= base;
	}

	return bn;
}

// * Base n -> Number
static int
to_number(string number, int base)
{
	int number = 0;

	for (int i = 0; i < number.length(); i++)
		number += pow(base, number.length() - i - 1) * base;

	return number;
}
}
;

// ? Parser
class Parser
{
public:
	// * Number -> Morse
	string to_morse(string number, Key &key)
	{
		string morse = "";

		for (char n : number)
			morse += string(1, key.get_value(n));

		return morse;
	}

	// * Morse -> Number
	string to_number(string morse, Key &key)
	{
		string number = "";

		for (char m : morse)
			number += string(1, key.get_value(m));

		return number;
	}
};

// ? TMC
class TalhaMorseCode
{
public:
	// * Encoder
	static vector<string> encode(string &text, Key &key)
	{
		vector<string> tmc;

		for (char c : text)
		{
			// ! Get morse number
			string number = Conversion::to_base(c, key.get_base());

			// ! Push morse code to TMC
			tmc.push_back(Parser::to_morse(number, key));
		}

		return tmc;
	}

	// * Decoder
	static string decode(vector<string> &code, Key &key)
	{
		string text = "";

		for (string morse : code)
		{
			// ! Get morse number
			string number = Parser::to_number(morse, key);

			// ! Add number to text
			text += Conversion::to_number(number, key.get_base());
		}

		return text;
	}
};

// ? Entry Point
int main()
{
}
