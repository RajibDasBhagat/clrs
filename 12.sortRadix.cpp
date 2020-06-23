
#include<iostream>
using namespace std;

void output(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout<<"\n";
}

int getMax(int arr[], int n){
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to the digit represented by exp.
void countSort(int arrA[], int n, int exp)
{
    int arrB[n]; // output array
    int i, arrC[10] = {0};


    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        arrC[ (arrA[i]/exp)%10 ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        arrC[i] += arrC[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--){
        arrB[arrC[ (arrA[i]/exp)%10 ] - 1] = arrA[i];
        arrC[ (arrA[i]/exp)%10 ]--;
        output(arrB,n);
    }
}

void radixsort(int arrA[], int n){
    int m = getMax(arrA, n);
    // Do counting sort for every digit.
    // instead of passing digit number, exp is passed. exp is 10^i where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arrA, n, exp);
}

int main()
{
    //int arrA[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int arrA[] = {329,457,657,839,436,720,355,426};
    int n = sizeof(arrA)/sizeof(arrA[0]);
    radixsort(arrA, n);

    return 0;
}
