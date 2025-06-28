#include <iostream>

using namespace std;

int linear_search(int array[], int size, int target)
{
    //* If the array is not NULL
    if (array != NULL)
    {
        //* Treverse the array to find the element
        for (int i = 0; i < size; i++)
            if (array[i] == target)
                return i;
    }

    return -1;
}

int main()
{
    //! Binary Search
    int target = 6, array[] = {0, 4, 3, 7, 5, 6, 11}, index = linear_search(array, sizeof(array) / sizeof(array[0]), target);

    //! Display output
    cout << "The target " << target << " is located at index " << index << endl;
}
