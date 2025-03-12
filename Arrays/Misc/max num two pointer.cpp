#include <iostream>

using namespace std;

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(array) / sizeof(array[0]);
    int i = 1, j = n - 1;
    int max = array[0];
    
    while (i < j)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[j] > max)
        {
            max = array[j];
        }
        i++;
        j--;
    }
    cout << "Max: " << max << endl;
}
