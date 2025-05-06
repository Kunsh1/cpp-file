#include<iostream>
using namespace std;

int c=0;

void maxHeapify(int* ar, int n, int i){
    int max=i;
    int left=i*2+1;
    int right=i*2+2;

   
    if(left<n && ar[left]>ar[max]){
        c++;
        max=left;
    }

    if(left<n && ar[left]<ar[max]){
        c++;
    }

    if(right<n && ar[right]>ar[max]){
        c++;
        max=right;
    }

    if(right<n && ar[right]<ar[max]){
        c++;
    }

    if(max!=i){
        int temp=ar[i];
        ar[i]=ar[max];
        ar[max]=temp;
        maxHeapify(ar, n, max);
    }
}

void buildMaxHeap(int* ar, int n){
    for(int i=n-1; i>=0; i--){
        maxHeapify(ar, n, i);
    }
}

void heapSort(int* ar, int n){
    buildMaxHeap(ar,n);
    for (int i=n-1; i>0 ; i--)
    {
        int temp=ar[0];
        ar[0]=ar[i];
        ar[i]=temp;

        maxHeapify(ar,i,0);
    }
}



void printArray(int*ar, int n){
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int p[6]={2,3,1,7,6,5};
    printArray(p,6);
    heapSort(p,6);
    printArray(p,6);
    cout<<"number of comparisons "<<c<<endl;

    return 0;
}