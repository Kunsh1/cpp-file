#include <iostream>
using namespace std;

int comparisons = 0;

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int partition(int array[], int start, int end) {
    int pivot = array[end];
    int smallerElementIndex = start - 1;
    
    for (int currentIndex = start; currentIndex < end; currentIndex++) {
        comparisons++;
        if (array[currentIndex] <= pivot) {
            smallerElementIndex++;
            int temp = array[smallerElementIndex];
            array[smallerElementIndex] = array[currentIndex];
            array[currentIndex] = temp;
        }
    }
    
    int temp = array[smallerElementIndex + 1];
    array[smallerElementIndex + 1] = array[end];
    array[end] = temp;

    return smallerElementIndex + 1;
}

void quickSort(int array[], int start, int end) {
    if (start < end) {
        int pivotIndex = partition(array, start, end);
        quickSort(array, start, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, end);
    }
}

int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int size = 6;

    cout << "Original array: ";
    printArray(array, size);

    quickSort(array, 0, size - 1);

    cout << "Sorted array: ";
    printArray(array, size);

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
