// time complexity: n
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int arr[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
//int arr[]={-2,-5,6,-2,-3,1,5,-6};


int maximumSubArray(int size){
    int i;
    int sumBefore=-99999, sumPresent=0;
    int starting=0,ending=0,temp=0;

    for(i=0;i<size;i++){
        sumPresent += arr[i];
        if(sumBefore<sumPresent){
            sumBefore=sumPresent;
            starting=temp;
            ending=i;
        }
        if(sumPresent<0){
            sumPresent=0;
            temp=i+1;
        }
    }
    cout<<"start: "<<starting<<" end: "<<ending<<" sum: "<<sumBefore;
    return starting,ending,sumBefore;
}

int main(){

    int size = sizeof(arr)/sizeof(arr[0]);
    int low=0,high=size-1;

    maximumSubArray(size);

    return 0;
}
