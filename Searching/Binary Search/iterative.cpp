#include <iostream>

using namespace std;

int binary_search(int array[], int size, int &target)
{
    //* If the array is not NULL
    if (array != NULL)
    {
        //* Initialize start and end indexes
        int start = 0, end = size - 1;

        //* Searching
        while (start <= end)
        {
            //* Initialize mid index
            int mid = (start + end) / 2;

            //* If the number at mid index is less than target
            if (array[mid] < target)
                start = mid + 1;

            //* If the number at mid index is greater than target
            else if (array[mid] > target)
                end = mid - 1;

            //* If the number at mid index is equal to target
            else if (array[mid] == target)
                return mid;
        }
    }

    return -1;
}

int main()
{
    //! Binary Search
    int target = 12, array[] = {-1, 0, 3, 4, 5, 9, 12}, index = binary_search(array, sizeof(array) / sizeof(array[0]), target);

    //! Display output
    cout << "The target " << target << " is located at index " << index << endl;
}
