#include<iostream>
using namespace std;

void insertionSort(int*ar, int n){
    int c=0;
    for(int i=1;i<n;i++){
        int key = ar[i];
        int j = i-1;
        while(j>=0 ){
            c++;
            if(key<ar[j]){
                ar[j+1] = ar[j];
                j = j-1;
            }
            else{
                break;
            }
        }
        ar[j+1] = key;
    }
    cout<<"number od comparisons : "<<c<<endl;
}

void printArray(int*ar, int n){
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}   

int main(){

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int* p = new int[n];

    cout << "Enter the elements: "<<endl;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    printArray(p,n);
    insertionSort(p,n);
    printArray(p,n);

    return 0;
}