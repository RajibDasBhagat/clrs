//bfs
//adjacency matrix
//queue
//path from source to destination
#include<iostream>
#include<cstdio>

#define MAX 100
int adj[MAX][MAX];
int vertex;

int color[MAX];
int parent[MAX];
int discovery[MAX];
int finish[MAX];
#define NIL -1

int time=0;
using namespace std;

void output(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void input(int n){
    int v1,v2,wt,edge;
    cout<<"\nNo edges: ";
    cin>>edge;
    while(edge--){
        cin>>v1>>v2;
        adj[v1][v2]=1;
    }
}
void displayState(int n){

    int i,j;
    cout<<"\n color: ";
    for(i=0;i<n;i++){
            cout<<color[i]<<" ";
    }
    cout<<"\n";
}
void initial(int n){
    int i,j;
    //initial adj matrix
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            adj[i][j]=0;
            color[i]=0;
        }
    }
}

void dfs(int i,int n){
    cout<<i<<" ";

    time += 1;
    discovery[i]= time;
    color[i]=1;

    int j;
    for(j=0;j<n;j++){
        if(adj[i][j]==1 && color[i]==1){
                color[i]=1;
                parent[j]=i;
                dfs(j,n);
        }
    }
    color[i]=2;
    time +=1 ;
    finish[i]=time;
}

void dfsTraversal(int n){
    int i,start;
    for(i=0;i<n;i++){
        color[i]=0;
        parent[i]=NIL;
    }
    cout<<"start:";
    cin>>start;
    for(i=start;i<n;i++){
        if(color[i]==0){
            dfs(i,n);
        }
    }
}

int main(){
    int n;
    cout<<"No of vertex:";
    cin>>n;

    //input weights
    input(n);
    cout<<"weights:\n";
    output(n);

    //bfs traverse
    dfsTraversal(n);

    cout<<"\nstart  finish\n";
    for(int i=0;i<n;i++){
        cout<<discovery[i]<<" "<<finish[i]<<"\n";
    }
    return 0;
}


