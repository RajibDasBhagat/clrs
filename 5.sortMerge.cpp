// time complexity: n log n
// not in-place sorting
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

void merge(int low,int mid, int high){
    int left,right;
    left = mid - low + 1;
    right = high - mid;

    int arr1[left],arr2[right];
    int i,j,k;
    //copy arrays
    for(i=0;i<left;i++){
        arr1[i]=arr[low+i];
    }
    for(j=0;j<right;j++){
        arr2[j]=arr[mid+1+j];
    }

    //merge arrays
    arr1[left+1]=-99999;
    arr2[right+1]=-99999;

    i=0;
    j=0;

    for(k=low; i<left && j<right;k++){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        else{
            arr[k]=arr2[j];
            j++;
        }
    }
    //copy back remaining
    while(i<left){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<right){
        arr[k]=arr2[j];
        j++;
        k++;
    }
    display(high+1);
}

void mergeSort(int low, int high){
    if(low<high){
        int mid = floor((low+high)/2);
        mergeSort(low,mid);
        mergeSort(mid+1,high);
        merge(low,mid,high);
    }
}

int main(){

    int size = sizeof(arr)/sizeof(arr[0]);
    int low=0;
    int high=size-1;

    mergeSort(low,high);
    return 0;
}
