//bfs
//adjacency matrix
//queue
//path from source to destination
#include<iostream>
#include<cstdio>

#define MAX 100
using namespace std;

void displaySize(int length){
    int i;
    cout<<"Length: ";
    for(i=1;i<=length;i++){
        cout<<i<<" ";
    }
    cout<<"\n";
}
void displayPrize(int price[], int length){
    int i;
    cout<<"Price: ";
    for(i=1;i<=length;i++){
        cout<<price[i]<<" ";
    }
    cout<<"\n";
}
int max(int a, int b){ return a>b?a:b;}

int cutRod(int price[],int length){
    int opti;
    if(length==0){
        return 0;
    }
    opti=-9999;
    for(int i=1;i<=length;i++){
        opti=max(opti, price[i] + cutRod(price,length-i));
    }
    return opti;
}
int main(){
    int length;
    cout<<"Max Length cut 1,2,3,...n: ";
    cin>>length;

    int price[]={-99,1,5,8,9,10,17,17,20,24,30};
    /*int price[MAX];

    for(int i=1;i<=length;i++){
        cin>>price[i];
    }*/

    displaySize(length);
    displayPrize(price,length);

    int optimal;
    optimal=cutRod(price,length);
    cout<<"optimal: "<<optimal;

    return 0;
}
