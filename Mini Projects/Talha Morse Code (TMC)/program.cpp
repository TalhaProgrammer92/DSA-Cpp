#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>

using namespace std;

// ? Decimal (ASCII) -> Ternary (base 3)
string ascii_to_ternary(int ascii)
{
	// * To store ternary
	string ternary = "";

	// * Conversion
	while (ascii > 0)
	{
		ternary = to_string(ascii % 3) + ternary;
		ascii /= 3;
	}

	return ternary;
}

// ? Ternary (Base 3) -> Decimal (ASCII)
char ternary_to_ascii(string &ternary)
{
	// * To store ASCII
	int ascii = 0, limit = ternary.length();

	// * Conversion
	for (int i = 0; i < limit; i++)
		ascii += (ternary[i] - '0') * pow(3, limit - i - 1);

	return ascii;
}

// ? Parse Ternary for TMC
string parse_ternary(const string &ternary, unordered_map<char, char> &key)
{
	string tmc = "";

	for (char c : ternary)
		tmc += key[c];

	return tmc;
}

// ? Parse TMC for Ternary
string parse_tmc(const string &tmc, unordered_map<char, char> &key)
{
	return parse_ternary(tmc, key);
}

// ? Encoder
vector<string> encode(const string &text, unordered_map<char, char> &key)
{
	vector<string> tmc;

	for (char c : text)
		tmc.push_back(parse_ternary(ascii_to_ternary(c), key));

	return tmc;
}

int main()
{
	unordered_map<char, char> key;
	key['0'] = '.';
	key['1'] = '~';
	key['2'] = '|';

	const string text = "My name is Talha Ahmad";
	cout << "Text: " << text << "\nTMC: ";
	for (string s : encode(text, key))
		cout << s;
	cout << endl;
}
