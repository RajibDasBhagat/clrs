// time complexity: n^2
// in-place sorting
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int arr[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};


void display(int size){
    int i;
    for(i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void insertionSort(int arr[],int size){
    int i,j,key;
    for(j=1;j<size;j++){
        key=arr[j];
        i=j-1;
        while(i>=0 and arr[i]>key){
           arr[i+1]=arr[i];
           i=i-1;
        }
        arr[i+1]=key;
        display(size);
    }
}


int main(){

    int size = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,size);

    return 0;
}
