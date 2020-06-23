
#include<iostream>
#include<cstdlib>
#include<cstring>

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

void selectionSort(int start[], int finish[], int n){
    int i, j, small;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++){
        small = i;
        for (j = i+1; j < n; j++)
            if (finish[j] < finish[small])
                small = j;
        // Swap the found minimum element with the first element
        swap(&finish[small], &finish[i]);
        swap(&start[small], &start[i]);
    }
    cout<<"\nstart : ";
    output(start,n);
    cout<<"finish: ";
    output(finish,n);
}

void outputActivity(int activity[], int n){
    int i;
    for(i=0;i<n;i++){
        if(activity[i] != 0){
            cout<<activity[i]<<" ";
        }
    }
}
void iterativeGreedy(int start[], int finish[], int j,int n){
    j = j+1;
    int activity[n]={j};
    int i;
    for(i=1;i<=n;i++){
        if(start[i]>=finish[j]){
            activity[i]=i+1;
            j=i;
        }
    }
    outputActivity(activity,n);
}

int recursiveGreedy(int start[], int finish[],int k, int size){

    int m=k+1;
    cout<<m<<" ";
    while(m<=size && start[m]<finish[k]){//find first acitvity
        m++;
    }
    if(m<=size){
        return recursiveGreedy(start,finish,m,size);
    }
}
int main(){

    int start[]={0,5,3,5,6,8,8,2,12,1,3};
    int finish[]={6,7,9,9,10,11,12,14,16,4,5};

    int size=sizeof(start)/sizeof(start[0]);
    cout<<"start: ";
    output(start,size);
    cout<<"finish: ";
    output(finish,size);

    //sort by finish time first
    cout<<"\nsorted: ";
    selectionSort(start, finish, size);

    cout<<"\nRecursive: ";
    recursiveGreedy(start,finish,0,size);

    cout<<"\nIterative: ";
    iterativeGreedy(start,finish,0,size);

    return 0;
}
