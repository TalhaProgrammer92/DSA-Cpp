#include <iostream>

using namespace std;

//? Series: 0 1 2 2 4 4 6 8 8 16 10 32
int series(int num1, int num2, int end)
{
    //* Count the number of nums
    static int count = 0;

    //* Stop Recursion when count becomes end
    if (count == end)
        return 0;
    
    //* Print the numbes
    cout << num1 << ' ' << num2 << ' ';
    count++;

    //* Return next number
    return series(num1 + 2, num2 * 2, end);
}

int main()
{
    series(0, 1, 6);
}
