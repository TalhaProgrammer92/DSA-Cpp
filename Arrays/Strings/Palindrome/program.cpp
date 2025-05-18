#include <iostream>

using namespace std;

//? This is my own approach ;-)

int main() {
	system("cls");

	string s = "racecar";
	// string s = "A man, a plan, a canal: Panama";		//! Does not work due to non alphanum characters
	int c = s[0];

	for (int i = 1; i < s.length(); i++)
		c ^= s[i];
	
	switch (s.length() % 2)
	{
	case 0:		// Even
		(c == 0) ? cout << "It's a palindrome" : cout << "It's not a palindrome";
		break;
	
	case 1:		// Odd
		(c == s[(int) (s.length() / 2)]) ? cout << "It's a palindrome" : cout << "It's not a palindrome";
		break;
	}

	cout << endl;

	return 0;
}