// time complexity: n
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

//int arr[]={2,1,3,4,7}; //3(n-1)/2 comparison
int arr[]={2,7,1,3,14,-5}; //3n/2-2 comparison

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void display(int size){
    int i;
    for(i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void minMaxEven(int arr[], int size){
    int min=arr[0];
    int max=arr[1];
    int currMin,currMax;

    for(int i=2;i<size;i+=1){
        if(arr[i]>arr[i+1]){
            currMax=arr[i];
            currMin=arr[i+1];
        }
        else{
            currMax=arr[i+1];
            currMin=arr[i];
        }
        if(currMin<min){
            min=currMin;
        }
        if(currMax>max){
            max=currMax;
        }
    }
    cout<<"min: "<<min<<" max: "<<max;

}
void minMaxOdd(int arr[], int size){

    int min=arr[0];
    int max=arr[0];
    int currMin,currMax;

    for(int i=1;i<size;i+=2){
        if(arr[i]>arr[i+1]){
            currMax=arr[i];
            currMin=arr[i+1];
        }
        else{
            currMax=arr[i+1];
            currMin=arr[i];
        }
        if(currMin<min){
            min=currMin;
        }
        if(currMax>max){
            max=currMax;
        }
    }
    cout<<"min: "<<min<<" max: "<<max;
}

int main(){

    int size = sizeof(arr)/sizeof(arr[0]);
    display(size);
    if(size%2==0){
        minMaxEven(arr,size);
    }
    else{
        minMaxOdd(arr,size);
    }
    return 0;
}
