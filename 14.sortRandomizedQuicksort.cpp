// time complexity worst: n^2
// time complexity best/average: n log n
#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include <cstdlib>

using namespace std;

int arr[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
//int arr[]={ 2, 1, 13, 5, 6, 7 };
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
int partition(int low, int high){
    int item = arr[high];
    int i = low - 1;
    for(int j = low;j<high;j++){
        if(arr[j]<=item){
            i += 1;
            swap(arr[i],arr[j]);
        }
        display(size);
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

int random(int low, int high){
   srand(time(NULL));
   return low+rand()%(high-low);
}
int randomizedPartition(int low, int high){
    int i=random(low,high);
    swap(arr[high],arr[i]);
    return partition(low,high);
}
int randomizedQuickSort(int low,int high){
    if(low<high){
        int mid = randomizedPartition(low,high);
        randomizedQuickSort(low,mid-1);
        randomizedQuickSort(mid+1,high);
    }
}

int main(){

    int low = 0;
    int high = size-1;
    randomizedQuickSort(low,high);

    return 0;
}
