#include <iostream>

using namespace std;

int main()
{
    // Declare an array with a fixed size of 5 integers
    const int size = 5;
    int array[size];

    // Fill elements in the array
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> array[i];
    }
    
    // Print the elements in the array
    cout << "\nArray elements: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
