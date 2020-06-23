#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void output(int arr[], int size){
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void selectionSort(int arr[], int n){
    int i, j, small;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++){
        small = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[small])
                small = j;
        // Swap the found minimum element with the first element
        swap(&arr[small], &arr[i]);
        output(arr,n);
    }
}

int main()
{
    //int arr[] = {64, 25, 12, 22, 11};
    int arr[]={-2,-5,6,-2,-3,1,5,-6};
    int n = sizeof(arr)/sizeof(arr[0]);
    output(arr,n);
    selectionSort(arr, n);
    return 0;
}
