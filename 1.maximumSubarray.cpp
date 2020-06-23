// time complexity: n log n
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

//int arr[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
int arr[]={-2,-5,6,-2,-3,1,5,-6};
int start,end;

int max(int a, int b){
    return (a>b? a:b);
}

int max(int a, int b, int c){
    return max(max(a,b),c);
}
int maximumCrossSubArray(int low, int mid, int high){
    int leftSum = -999999, sum = 0;
    int i;

    for(i=mid;i>=low;i--){
        sum += arr[i];
        if(sum>leftSum){
            leftSum = sum;
            start=i;
        }
    }
    int rightSum = -999999;
    sum = 0;
    int j;
    for(j=mid+1;j<=high;j++){
        sum += arr[j];
        if(sum>rightSum){
            rightSum = sum;
            end=j;
        }
    }
    return (start,end,leftSum+rightSum);
    //return max(leftSum,rightSum,leftSum+rightSum);
}

int maximumSubArray(int low, int high){
    int mid;
    int leftLow,leftHigh,leftSum;
    int rightLow,rightHigh,rightSum;
    int crossLow,crossHigh,crossSum;

    if(high==low){
        return (low,high,arr[low]);
    }
    else{
        mid=floor((low+high)/2);
        leftLow,leftHigh,leftSum = maximumSubArray(low,mid);
        rightLow,rightHigh,rightSum = maximumSubArray(mid+1,high);
        crossLow,crossHigh,crossSum = maximumCrossSubArray(low,mid,high);

        if(leftSum >= rightSum && leftSum >= crossSum){
            return (leftLow,leftHigh,leftSum);
        }
        else if(rightSum >= leftSum && rightSum >= crossSum){
            return (rightLow,rightHigh,rightSum);
        }
        else{
            return (crossLow,crossHigh,crossSum);
        }
    }
}

int main(){

    int size = sizeof(arr)/sizeof(arr[0]);
    int low=0,high=size-1;
    int sum;
    sum = maximumSubArray(low, high);
    cout<<"start: "<<start<<" end: "<< end <<" sum: "<<sum;
    return 0;
}
