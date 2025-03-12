#include <iostream>

using namespace std;

int main()
{
    //* Array/Variables
    int array[] = {2, 1, 5, 8, 4, 6, 9, 7};
    int size = sizeof(array) / sizeof(int), max = array[0];

    //* Algorithm
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    //* Display Result
    cout << "Max: " << max << endl;
}