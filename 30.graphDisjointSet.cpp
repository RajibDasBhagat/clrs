
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct set{
  int root;
  int rank;
};

int Find(set sets[], int x){
    if ( x != sets[x].root)
        sets[x].root = Find(sets, sets[x].root);
    return sets[x].root;
}


void Union(set sets[],int key,int key1){
     int x=Find(sets,sets[key].root);
     int y=Find(sets,sets[key1].root);
     if (sets[x].rank > sets[y].rank)
        sets[y].root = x;
     else{
        sets[y].root = x;
        if(sets[x].rank==sets[y].rank){
           sets[x].rank = sets[x].rank+1;
        }
     }
}

void display(set sets[],int n,int cc){
    int i;
        cout<<"vertex"<<" "<<"root"<<" "<<"rank\n";
    for(i=0;i<n;i++){
        cout<<i<<" "<< sets[i].root<<" "<<sets[i].rank<<"\n";
    }
    cout<<"\nConnected Components: "<<cc<<endl;
}

void makeSet(set sets[], int n){
    for(int i=0;i<n;i++){
       sets[i].root=i;
       sets[i].rank=0;
    }
}
int main() {
    int no_vertex;
    cout<<"vertex: ";
    cin>> no_vertex;
    int cc=no_vertex;

    //makeset
    struct set *sets =(struct set*) malloc( (no_vertex+1) * sizeof(struct set) );

    makeSet(sets, no_vertex );
    display(sets,no_vertex,cc);

    while(1){
        int choice;
        cout<<"\n1. Union";
        cout<<"\n2. Find";
        cout<<"\n0. Exit";
        cout<<"\n________________________\n";
        cin>>choice;
        switch(choice){
        case 1:
            int key, key1, x, y;
            cout<<"\nEnter two keys: ";
            cin>>key>>key1;
            x=Find(sets,sets[key].root);
            y=Find(sets,sets[key1].root);
            if(x!=y){
               Union(sets,key,key1);
               cc--;
            }
            else{
                cout<<"\n cycle detected \n";
            }
            display(sets,no_vertex,cc);
            break;
        case 2:
           cin>>key;
           cout<<"Root: "<<Find(sets,sets[key].root)<<endl;
           break;
        case 0:
            exit(0);
        }
    }
    return 0;
}
