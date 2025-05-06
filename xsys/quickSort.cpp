#include <iostream>
using namespace std;

int c =0;

void printArray(int Ar[], int size) {
    for (int i = 0; i < size; i++) {
        cout << Ar[i] << " ";
    }
    cout << endl;
}

int partition(int Ar[], int p, int r){
    int x=Ar[r]; 
    int i =p-1;
    for (int j=p; j<r; j++){
        c++;
        if (Ar[j] <= x){ 
            i++;
            int temp =Ar[i];
            Ar[i] =Ar[j];
            Ar[j] =temp;
        }
    }
    int temp=Ar[i + 1];
    Ar[i + 1]=Ar[r];
    Ar[r]=temp;

    return i + 1; 
}

void quicksort(int Ar[], int p, int r) {
    if (p < r) {
        int q = partition(Ar, p, r);
        quicksort(Ar, p, q - 1);
        quicksort(Ar, q + 1, r);
    }
}


int main() {
    int arr[]= {12, 11, 13, 5, 6, 7};
    int n=6;

    quicksort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    cout<<"Number of comparisons: "<<c<<endl;

    return 0;
}
