#include<iostream>
using namespace std;

int comparisons = 0;

void countSort(int* array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        comparisons++;  // Count comparison for max finding
        if (array[i] > max) {
            max = array[i];
        }
    }

    int* output = new int[size];  
    int* count = new int[max + 1];

    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
    
    delete[] output;
    delete[] count;
}

void printArray(int* array, int size) {
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}   

int main() {
    int array[8] = {2,3,1,7,6,3,2,5};
    
    cout << "Original array: ";
    printArray(array, 8);
    
    countSort(array, 8);
    
    cout << "Sorted array: ";
    printArray(array, 8);
    
    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}