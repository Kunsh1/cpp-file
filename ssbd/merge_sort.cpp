
#include<iostream>
using namespace std;

int c = 0;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int start, int mid, int end) {
    int sizeLeftHalf = mid + 1;  // size of left half
    int sizeRightHalf = end - mid;       // size of right half
    
    int temp[sizeLeftHalf + sizeRightHalf];  // single temporary array for merged result
    int left = start;   // pointer to left half
    int right = mid + 1;// pointer to right half
    int k = 0;         // pointer to temp array
    
    // Compare and merge elements
    while (left <= mid && right <= end) {
        c++;  // count comparisons
        if (arr[left] <= arr[right]) {
            temp[k++] = arr[left++];
        } else {
            temp[k++] = arr[right++];
        }
    }
    
    // Copy remaining elements
    while (left <= mid) {
        temp[k++] = arr[left++];
    }
    while (right <= end) {
        temp[k++] = arr[right++];
    }
    
    // Copy back to original array
    for (int i = 0; i < k; i++) {
        arr[start + i] = temp[i];
    }
}

void mergeSort(int arr[], int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = 6;

    cout << "Original array: ";
    printArray(arr, n);

    mergeSort(arr, 0, n-1);

    cout << "\nSorted array: ";
    printArray(arr, n);

    cout << "\nNumber of comparisons made during sorting: " << c << endl;

    return 0;
}