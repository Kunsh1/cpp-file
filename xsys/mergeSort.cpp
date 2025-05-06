
#include<iostream>
using namespace std;

int c =0;

void printArray(int Ar[], int size) {
    for (int i = 0; i < size; i++) {
        cout << Ar[i] << " ";
    }
    cout << endl;
}

void merge(int* ar, int start, int mid, int end){
    int leftSize = mid-start+1;
    int rightSize = end-mid;
    
    int* left = new int[leftSize];
    int* right = new int[rightSize];
    
    for(int i=0; i<leftSize; i++){
        left[i] = ar[start + i];
    }
    for(int i=0; i<rightSize; i++){
        right[i] = ar[mid+1+i];
    }

    int i=0, j=0, k=start;
    
    while(i <leftSize && j <rightSize){
        c++;
        if(left[i] <= right[j]) {
            ar[k++] = left[i++];
        } else {
            ar[k++] = right[j++];
        }
    } 
    while(i < leftSize){
        ar[k++] = left[i++];
    }
    while(j < rightSize){
        ar[k++] = right[j++];
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int* ar, int start, int end){
    if(start<end){
        int mid =(start + end)/2;
        mergeSort(ar, start, mid);
        mergeSort(ar, mid+1, end);
        merge(ar, start, mid, end);
    }
}

int main() {
    int arr[]= {12, 11, 13, 5, 6, 7};
    int n=6;

    mergeSort(arr,0,n-1);

    cout<<"Sorted array: ";
    printArray(arr, n);

    cout<<"Number of comparisons: "<<c<<endl;

    return 0;
}