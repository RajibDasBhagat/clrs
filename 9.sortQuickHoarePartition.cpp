// time complexity worst: n^2
// time complexity best/average: n log n
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
int arr [] = {10, 7, 8, 9, 15, 5};
int size = sizeof(arr)/sizeof(arr[0]);

void display(int size){
    int i;
    for(i=0;i<size;i++){
            cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int hoarePartition(int arr[],int low, int high){
    display(size);
    int pivot = arr[high];
    // Index of smaller element
    int i = (low - 1);
    for (int j=low; j< high; j++){
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot){
            // increment index of smaller element
            i += 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void hoareSort(int arr[], int low, int high){
    if (low < high){
        //pi is partitioning index, arr[p] is now at right place
        int pi = hoarePartition(arr,low,high);
        hoareSort(arr, low, pi-1);
        hoareSort(arr, pi+1, high);
    }
}

int main(){

    hoareSort(arr,0,size-1);

}
