//bfs
//adjacency matrix
//queue
//path from source to destination
#include<iostream>
#include<cstdio>

#define MAX 100
int adj[MAX][MAX];
int vertex;

#define INITIAL 1
#define WAITING 2
#define VISITED 3
int state[MAX];

int queue[MAX], front=-1, rear=-1;

using namespace std;

#define NIL -1
#define INFY 9999
int dist[MAX];
int parent[MAX];
int path[MAX];

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
        adj[v2][v1]=1;
    }
}
void displayState(int n){
    int i,j;
    for(i=0;i<n;i++){
            cout<<state[i]<<" ";
    }
    cout<<"\n";
}
void initial(int n){
    int i,j;
    //initial adj matrix
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            adj[i][j]=0;
        }
    }
}
int isEmptyQueue(){
    if(front==-1 || front==rear+1){
        return 1;
    }
    else{
        return 0;
    }
}
void insertQueue(int start){
    if(rear==MAX-1){
        cout<<"Overflow\n";
    }
    else{
        if(front == -1){
            front = 0;
        }
        rear += 1;
        queue[rear]=start;
    }
}
int deletequeue(){
    int temp;
    if(front==-1 && rear==-1){
        cout<<"Underflow\n";
    }
    temp=queue[front];
    front++;
    return temp;

}
void bfs(int start,int n){
    int i;
    insertQueue(start);
    state[start]=WAITING;
    parent[start]=NIL;
    dist[start]=0;
    while(!isEmptyQueue()){
        start=deletequeue();
        cout<<start<<" ";
        state[start]=VISITED;

        for(i=0;i<n;i++){
            if(adj[start][i]==1 && state[i]==INITIAL){
                insertQueue(i);
                state[i]=WAITING;
                parent[i]=start;
                dist[i]=dist[start]+1;
            }
        }
    }
    cout<<"\n";
}
void bfsTraversal(int n){
    int i,start;
    for(i=0;i<n;i++){
        state[i]=INITIAL;
        parent[i]=NIL;
        dist[i]=INFY;
    }
    cout<<"Initial State:";
    displayState(n);
    cout<<"start:";
    cin>>start;
    bfs(start,n);
}

int main(){
    int n;
    cout<<"No of vertex:";
    cin>>n;

    //cout<<"initial:\n";
    initial(n);
    //output(n);

    //input weights
    input(n);
    cout<<"weights:\n";
    output(n);

    //bfs traverse
    bfsTraversal(n);

    //shortest path
    int dest,u,count=0;
    cout<<"Destination: ";
    cin>>dest;
    while(dest != NIL){
        count++;
        path[count]=dest;
        u=parent[dest];
        dest=u;
    }
    int i;
    cout<<"\nShortest Path: ";
    for(i=count;i>0;i--){
        cout<<path[i]<<" ";
    }

    return 0;
}

