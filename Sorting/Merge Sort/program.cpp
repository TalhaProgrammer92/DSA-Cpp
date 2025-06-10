#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &array, int start, int mid, int end)
{
    // * Necessary indices for sorting
    int left_start = start, right_start = mid + 1;
    vector<int> temp;

    // * Go-through left and ride side numbers to sort them
    while (left_start <= mid && right_start <= end)
        (array[left_start] <= array[right_start]) ?
            temp.push_back(array[left_start++]):    // * If left side value is less/equal to right side
            temp.push_back(array[right_start++]);   // * If right side value is less than to left side

    // * Remaining values of left side
    for (int i = left_start; i <= mid; i++)
        temp.push_back(array[i]);

    // * Remaining values of right side
    for (int i = right_start; i <= end; i++)
        temp.push_back(array[i]);

    // * Copy elements of temp to original array
    for (int i = 0; i < temp.size(); i++)
        array[i + start] = temp[i];
}

void sort(vector<int> &array, int start, int end)
{
    // * Only if the start value does not exceed the value of end
    if (start < end)
    {
        // * Mid of the given array's length
        int mid = start + (end - start) / 2;

        // * Divide and Conquer
        sort(array, start, mid);   // ? Left half
        sort(array, mid + 1, end); // ? Right half

        // * Merge array partitions
        merge(array, start, mid, end);
    }
}

// ? Display vector array
void display(vector<int> &array)
{
    for (int num : array)
        cout << num << ' ';
    cout << endl;
}

int main()
{
    vector<int> array = {12, 31, 35, 8, 32, 17};

    sort(array, 0, array.size() - 1);

    display(array);
}
