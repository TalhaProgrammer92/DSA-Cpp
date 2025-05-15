#include <iostream>

using namespace std;

int binary_search(int array[], int size, int &target)
{
    if (array != NULL)
    {
        int start = 0, end = size - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (array[mid] < target)
                start = mid + 1;
            
            else if (array[mid] > target)
                end = mid - 1;
            
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
