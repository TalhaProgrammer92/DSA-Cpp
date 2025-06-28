#include <iostream>
#include <vector>
#include <algorithm> // for sort()
using namespace std;

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    // Step 1: Create n empty buckets
    vector<float> buckets[n];

    // Step 2: Put array elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i]; // Index in bucket
        buckets[index].push_back(arr[i]);
    }

    // Step 3: Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Step 4: Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float value : buckets[i]) {
            arr[index++] = value;
        }
    }
}

// Utility function to print array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    float arr[] = {0.897f, 0.565f, 0.656f, 0.123f, 0.665f, 0.343f};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    bucketSort(arr, n);

    cout << "Sorted array:   ";
    printArray(arr, n);

    return 0;
}
