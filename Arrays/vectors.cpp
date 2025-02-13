#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Create an empty vector of integers
    vector<int> my_vector;

    // Add elements to the vector
    my_vector.push_back(10);
    my_vector.push_back(20);
    my_vector.push_back(30);
    my_vector.push_back(40);
    
    // Print the vector
    cout << "Vector elements: ";
    for (/* const */ int element : my_vector)     // For-each loop
        cout << element << " ";
}
