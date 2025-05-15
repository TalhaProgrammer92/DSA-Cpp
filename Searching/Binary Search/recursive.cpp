#include <iostream>

using namespace std;

int binary_search(int array[], int target, int start, int end)
{
    //* Initialize mid index
    int mid = start + (end - start) / 2;

    //* If the number at mid index is less than target
    if (array[mid] < target)
        return binary_search(array, target, mid + 1, end);

    //* If the number at mid index is greater than target
    else if (array[mid] > target)
        return binary_search(array, target, start, mid - 1);

    //* If the number at mid index is equal to target
    else if (array[mid] == target)
        return mid;

    return -1;
}

int main()
{
    //! Binary Search
    int target = 12, array[] = {-1, 0, 3, 4, 5, 9, 12}, size = sizeof(array) / sizeof(array[0]), index = binary_search(array, target, 0, size - 1);

    //! Display output
    cout << "The target " << target << " is located at index " << index << endl;
}
