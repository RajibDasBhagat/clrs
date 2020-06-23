// time complexity: n log n
// in-place sorting
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

//int arr[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
int arr[]={ 2, 1, 13, 5, 6, 7 };
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

int parent(int i){ return floor(i/2);}
int left(int i){ return 2*i;}
int right(int i){ return ((2*i)+1);}
//maintain heap property
void heapify(int size, int i)
{
    int largest; // Initialize largest for/as root
    int l = left(i); // left = 2*i + 1
    int r = right(i); // right = 2*i + 2

    // If left child is larger than root
    if (l < size && arr[l] > arr[i]){
        largest = l;
    }
    else{
        largest = i;
    }
    // If right child is larger than largest so far
    if (r < size && arr[r] > arr[largest])
        largest = r;
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(size, largest);
    }
}

// main function to do heap sort
void heapSort(int size)
{
    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(size, i);

    // One by one extract an element from heap
    for (int i = size - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(i, 0);
        display(size);
    }
}
int main(){

    int size = sizeof(arr)/sizeof(arr[0]);
    heapSort(size);

    return 0;
}
