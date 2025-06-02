#include <iostream>

using namespace std;

int main() {
	pair<string, int> p = {"Two", 2};

	cout << '(' << p.first << ", " << p.second << ')' << endl;

	pair<string, pair<char, int>> _pair = {"Pair", {'a', 97}};

	cout << '[' << _pair.first << ", (" << _pair.second.first << ", " << _pair.second.second << ")]" << endl;

	return 0;
}