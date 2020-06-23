// time complexity worst: linear
// time complexity best/average:
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
int arrA[] = {2,5,3,0,2,3,0,3};
int size = sizeof(arrA)/sizeof(arrA[0]);

void display(int arr[],int in,int n){
    int i;
    for(i=in;i<=n;i++){
            cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void countingSort(int arrA[],int arrB[], int k){
    int arrC[k+1];
    int i,j;
    for(i=0;i<k+1;i++){
        arrC[i]=0;
    }
    //display(arrC,k+1);
    for(j=0;j<size;j++){
        arrC[arrA[j]] += 1;
        //arrC contains the number of elements equal to i
        //cout<<"\narrC_+1: ";
        //display(arrC,0,k);
    }

    for(i=1;i<k+1;i++){
        arrC[i] += arrC[i-1];
        //arrC contains the number of elements less than or equal to i
        //cout<<"\narrC_+i-1: ";
        //display(arrC,0,k);
    }

    for(j=size-1;j>=0;j--){
            arrB[arrC[arrA[j]]]=arrA[j];
            arrC[arrA[j]] -= 1;
        cout<<"\narrB: ";
        display(arrB,1,size);
        //cout<<"\narrC_+i-1: ";
        //display(arrC,0,k);
    }
}

int main(){
    int arrB[size];
    int k = 5;
    cout<<"\narrA: ";
    display(arrA,0,size-1);

    countingSort(arrA,arrB,k);

}
