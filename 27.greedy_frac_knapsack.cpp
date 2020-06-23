
#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

int  weight[]={20,30,10};
float  prices[]={100,120,60};

float maximum(int  a, int b){return a>b? a : b;}

void display(float arr[],int items){
    for(int i=0;i<items;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void fraction(int  frac[], int items, int Weight){

    for(int i=0;i<items;i++){
        frac[i]= prices[i]/weight[i];
    }
    //display(frac,items);
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int n){
    int i, j, small;
    for (i = 0; i < n-1; i++){
        small = i;
        for (j = i+1; j < n; j++)
            if (arr[j] > arr[small])
                small = j;
        // Swap the found minimum element with the first element
        swap(&arr[small], &arr[i]);
        swap(&weight[small],&weight[i]);
        swap(prices[small],prices[i]);
    }
    //display(weight,n);
    //display(prices,n);
    //display(arr,n);
}
void knap(int items, int W){
    int i;
    float x[items];
    for(i=0;i<items;i++){
        x[i] = 0;
    }
    float total = 0;
    float profit = 0;
    for(i=0;i<items;i++){
        if (total + weight[i] <= W){
            x[i] = weight[i];
            total += weight[i];
            profit += prices[i];
            cout<<prices[i]<<" ";
        }
        else{
            x[i] = (W - total) / weight[i];
            total = W;
            profit += prices[i]*x[i];
            cout<<prices[i]*x[i]<<" ";
            break;
        }
    }
    cout<<"\n";
    display(x,items);
    cout<<profit<<" ";

}

int main(){
    int items=3;
    int knapsackWeight=50;

    int frac[items];
    fraction(frac,items,knapsackWeight);
    selectionSort(frac, items);
    knap(items,knapsackWeight);

    return 0;
}
