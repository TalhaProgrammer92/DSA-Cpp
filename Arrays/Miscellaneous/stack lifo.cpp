#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //! Variables
    string text;
    vector<char> stack;

    //! Take Input
    cout << "Enter a text: ";
    getline(cin, text);

    //! Read the input and push onto stack
    for (int i = 0; i < text.length(); i++)
        stack.push_back(text[i]);
    
    //! Display the text in reverse order using LIFO
    for (int i = 0; i < text.length(); i++)
    {
        cout << stack.back();
        stack.pop_back();
    }
    cout << endl;
}
