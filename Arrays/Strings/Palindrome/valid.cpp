#include <iostream>

using namespace std;

bool is_palindrome_two_pointer(string s)
{
	int start = 0, end = s.length() - 1;

	while (start <= end)
	{
		char a, b;

		do
		{
			if (!isalnum(s[start]))
				start++;

			a = tolower(s[start]);
		} while (!isalnum(a));

		do
		{
			if (!isalnum(s[end]))
				end--;

			b = tolower(s[end]);
		} while (!isalnum(b));

		if (a != b)
			return false;

		start++;
		end--;
	}

	return true;
}

int main()
{
	// string s = "racecar";
	string s = "Ac3?e3c&a";
	bool valid = is_palindrome_two_pointer(s);

	(valid) ? cout << "It's a palindrome" : cout << "It's not a palindrome";

	cout << endl;

	return 0;
}