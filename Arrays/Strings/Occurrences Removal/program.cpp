#include <iostream>

using namespace std;

//? s = "daadcbaabcbc", part = "abc" => s = "dab"

void remove_occurrences(string &s, string &part)
{
	if (s.length() == 0 || part.length() == 0)
		return;

	do
	{
		int i = s.find(part);

		if (i < s.length())
			s.erase(i, part.length());

	} while (s.find(part) < s.length());
}

int main() {
	string s = "daadcbaabcbc", part = "abc";

	remove_occurrences(s, part);

	cout << s << endl;

	return 0;
}