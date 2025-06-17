#include <iostream>
#include <stack>

using namespace std;

bool is_valid_parenthesis(string paren)
{
	// ? If has only one or no parenthesis
	if (paren.length() <= 1) return false;

	// ? Check if opening and clossing parenthesis exist or not
	stack<char> parenthesis;
	for (char p : paren)
	{
		// ? Push opening parenthesis onto stack
		if (p == '(' || p == '[' || p == '{')
			parenthesis.push(p);
		// ? Pop recently added open parenthesis and check if its closing one exist in correct place
		else
		{
			char last = parenthesis.top();
			
			switch (p)
			{
			case ')':
				if (last != '(')
					return false;
				break;
			
			case ']':
				if (last != '[')
					return false;
				break;
			
			case '}':
				if (last != '{')
					return false;
				break;
			
			default:
				return false;
			}
			
			parenthesis.pop();
		}
	}

	return parenthesis.empty();
}

int main()
{
	string parenthesis[] = {"({})", "({}]", "({}", "({[]}[])", "]"};

	for (string paren : parenthesis)
		cout << paren << " : " << is_valid_parenthesis(paren) << endl;
}
