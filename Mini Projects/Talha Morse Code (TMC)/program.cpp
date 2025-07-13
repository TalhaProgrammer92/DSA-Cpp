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

// ? TMC
class TalhaMorseCode
{
public:
	// * Encoder
	static vector<string> encode(string &text, Key &key)
	{
		vector<string> morse;

		// ! Parse
		for (char c : text)
		{
			string s = "";
			int num = c;

			// ! Convert
			while (num > 0)
			{
				s = string(1, key.get_symbol(num % key.get_base())) + s;
				num /= key.get_base();
			}

			morse.push_back(s);
		}

		return morse;
	}

	// * Decoder
	static string decode(vector<string> &morse, Key &key)
	{
		string text = "";

		// ! Parse
		for (string s : morse)
		{
			char chr = 0;

			for (int i = 0; i < s.length(); i++)
			{
				chr += key.get_number(s[i]) * pow(key.get_base(), s.length() - i - 1);
			}

			text += string(1, chr);
		}

		return text;
	}
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
	Key key({'!', '@', '#', '$', '%', '^', '&', '*', '(', ')'});
	
	string text = "The quick brown fox jumps over a lazy dog";

	vector<string> tmc = TalhaMorseCode::encode(text, key);
	cout << "TMC: "; display(tmc);
	
	cout << "Text: " << TalhaMorseCode::decode(tmc, key) << endl;
}
