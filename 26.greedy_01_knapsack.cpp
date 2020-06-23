
#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

int weight[]={10,20,30};
int prices[]={60,100,120};

int maximum(int a, int b){return a>b? a : b;}

void display(int arr[],int items){
    for(int i=0;i<items;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int knapRecursive(int items, int knapsackWeight){
    int i;
    int max=0;
    if(knapsackWeight==0 || items==0){
        return 0;
    }
    if(weight[items-1]>knapsackWeight){ // do not pick
        return knapRecursive(items-1,knapsackWeight);
    }
    else{
        return maximum(prices[items-1]+
                       knapRecursive(items-1,knapsackWeight-weight[items-1]),
                       knapRecursive(items-1,knapsackWeight));
    }
}

int knapIterative(int items, int W){

    int i, j;
    int k[items + 1][W + 1];

    for (i = 0; i <= items; i++){
        for (j = 0; j <= W; j++){
            if (i == 0 || j == 0){
               k[i][j] = 0;
            }
            else if(weight[i - 1]<=j){
                    k[i][j] = max(prices[i - 1] + k[i-1][j-weight[i-1]], k[i-1][j]);
            }
            else{
                 k[i][j]=k[i-1][j];
            }
        }
    }
    return k[items][W];
}

int main(){
    int items=3;
    int knapsackWeight=50;

    cout<<"weight: ";
    display(weight,items);
    cout<<"prices: ";
    display(prices,items);

    cout<<knapRecursive(items,knapsackWeight)<<"\n";
    cout<<knapIterative(items,knapsackWeight);
    return 0;
}
