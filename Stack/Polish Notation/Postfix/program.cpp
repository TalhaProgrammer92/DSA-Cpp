#include <iostream>
#include <stack>

using namespace std;

string infix_to_postfix(string &infix)
{
	string postfix = "";
	stack<char> s;

	for (char &c : infix)
	{
		// * Operand
		if (isalnum(c))
		{
			string str(1, c);
			postfix += str;
		}

		// * Operator
		else
		{
			if (c == ')')
			{
				while (!s.empty())
				{
					if (s.top() == '(') break;

					string str(1, s.top());
					postfix += str;

					s.pop();
				}

				// ! Pop the last '('
				if (!s.empty())
				{
					s.pop();
				}
			}
			else
				s.push(c);
		}
	}

	return postfix;
}

int main()
{
	string expression = "A+((B+C)+(D+E)*F)/G)", postfix = infix_to_postfix(expression);

	cout << "Infix:   " << expression << endl;
	cout << "Postfix: " << postfix << endl;
}
