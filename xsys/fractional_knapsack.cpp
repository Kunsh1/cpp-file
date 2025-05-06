#include<iostream>
using namespace std;

void merge(double* ratio, int* weight, int* value, int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;
    
    double* leftRatio = new double[leftSize];
    int* leftWeight = new int[leftSize];
    int* leftValue = new int[leftSize];
    
    double* rightRatio = new double[rightSize];
    int* rightWeight = new int[rightSize];
    int* rightValue = new int[rightSize];
    
    for (int i = 0; i < leftSize; i++) {
        leftRatio[i] = ratio[start + i];
        leftWeight[i] = weight[start + i];
        leftValue[i] = value[start + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightRatio[i] = ratio[mid + 1 + i];
        rightWeight[i] = weight[mid + 1 + i];
        rightValue[i] = value[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;
    
    while (i < leftSize && j < rightSize) {
        if (leftRatio[i] > rightRatio[j]) {
            ratio[k] = leftRatio[i];
            weight[k] = leftWeight[i];
            value[k] = leftValue[i];
            i++;
        } else {
            ratio[k] = rightRatio[j];
            weight[k] = rightWeight[j];
            value[k] = rightValue[j];
            j++;
        }
        k++;
    }
    
    while (i < leftSize) {
        ratio[k] = leftRatio[i];
        weight[k] = leftWeight[i];
        value[k] = leftValue[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        ratio[k] = rightRatio[j];
        weight[k] = rightWeight[j];
        value[k] = rightValue[j];
        j++;
        k++;
    }

    delete[] leftRatio;
    delete[] leftWeight;
    delete[] leftValue;
    delete[] rightRatio;
    delete[] rightWeight;
    delete[] rightValue;
}

void mergeSort(double* ratio, int* weight, int* value, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(ratio, weight, value, start, mid);
        mergeSort(ratio, weight, value, mid + 1, end);
        merge(ratio, weight, value, start, mid, end);
    }
}

double fractionalKnapsack(int W, int weight[], int value[], double ratio[], int n) {
    mergeSort(ratio, weight, value, 0, n - 1);

    double totalValue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (weight[i] <= W) {
            W -= weight[i];
            totalValue += value[i];
        } else {
            totalValue += (value[i] * (double)W / weight[i]);
            break;
        }
    }
    
    return totalValue;
}

int main() {
    int W = 50;
    int weight[] = {10, 20, 30};
    int value[] = {60, 100, 120};
    int n = sizeof(weight) / sizeof(weight[0]);
    
    double ratio[n];
    
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)value[i] / weight[i];
    }
    
    double maxValue = fractionalKnapsack(W, weight, value, ratio, n);
    
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
