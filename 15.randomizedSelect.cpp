// return ith smallest element;
// time complexity worst: n^2

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
int randomizedSelect(int low, int high, int i_th){
    if(low==high){
        return arr[low];
    }
    int mid = randomizedPartition(low,high);
    int k = mid - low + 1;
    if(i_th==k){
        //pivot is answer
        return arr[mid];
    }
    else if(i_th<k){
        return randomizedSelect(low,mid-1,i_th);
    }
    else{
        return randomizedSelect(mid+1,high,i_th-k);
    }
}

int main(){

    int low = 0;
    int high = size-1;
    int i_th;
    display(size);
    cout<<"i_th smallest: ";
    cin>>i_th;
    int found=randomizedSelect(low,high,i_th);
    cout<<found;
    return 0;
}
