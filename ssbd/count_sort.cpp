#include<iostream>
using namespace std;

int comparisons = 0;

void countSort(int arr[], int size) {
    // Find maximum element
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        comparisons++;  // Count comparison for finding max
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create count and output arrays
    int output[size];
    int count[max + 1];

    // Initialize count array with zeros
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Store count of each element
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    // Calculate cumulative count
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Build output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy output array to original array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}   

int main() {
    int arr[] = {2, 3, 1, 7, 6, 3, 2, 5};
    int size = 8;

    cout << "Original array: ";
    printArray(arr, size);

    countSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);
    
    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}