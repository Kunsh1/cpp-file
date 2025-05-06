#include<iostream>
using namespace std;

void printArray(int Ar[], int size) {
    for (int i = 0; i < size; i++) {
        cout << Ar[i] << " ";
    }
    cout << endl;
}

void merge(int* start, int* finish, int startIdx, int mid, int endIdx) {
    int leftSize = mid - startIdx + 1;
    int rightSize = endIdx - mid;

    int* leftStart = new int[leftSize];
    int* rightStart = new int[rightSize];
    int* leftFinish = new int[leftSize];
    int* rightFinish = new int[rightSize];

    for (int i = 0; i < leftSize; i++) {
        leftStart[i] = start[startIdx + i];
        leftFinish[i] = finish[startIdx + i];
    }

    for (int i = 0; i < rightSize; i++) {
        rightStart[i] = start[mid + 1 + i];
        rightFinish[i] = finish[mid + 1 + i];
    }

    int i = 0, j = 0, k = startIdx;

    while (i < leftSize && j < rightSize) {
        if (leftFinish[i] <= rightFinish[j]) {
            start[k] = leftStart[i];
            finish[k] = leftFinish[i];
            i++;
        } else {
            start[k] = rightStart[j];
            finish[k] = rightFinish[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        start[k] = leftStart[i];
        finish[k] = leftFinish[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        start[k] = rightStart[j];
        finish[k] = rightFinish[j];
        j++;
        k++;
    }

    delete[] leftStart;
    delete[] rightStart;
    delete[] leftFinish;
    delete[] rightFinish;
}

void mergeSort(int* start, int* finish, int startIdx, int endIdx) {
    if (startIdx < endIdx) {
        int mid = (startIdx + endIdx) / 2;
        mergeSort(start, finish, startIdx, mid);
        mergeSort(start, finish, mid + 1, endIdx);
        merge(start, finish, startIdx, mid, endIdx);
    }
}

int intervalScheduling(int start[], int finish[], int n) {
    mergeSort(start, finish, 0, n - 1);

    int count = 1;
    int lastFinishTime = finish[0];

    for (int i = 1; i < n; i++) {
        if (start[i] >= lastFinishTime) {
            count++;
            lastFinishTime = finish[i];
        }
    }

    return count;
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);

    int maxIntervals = intervalScheduling(start, finish, n);

    cout << "Maximum number of intervals that can be selected: " << maxIntervals << endl;

    return 0;
}
