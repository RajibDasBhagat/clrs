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

int n=8;
using namespace std;

//components
int label[MAX];

void output(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void input(){
    int v1,v2,wt,edge;
    cout<<"\nNo edges: ";
    cin>>edge;
    while(edge--){
        cin>>v1>>v2;
        adj[v1][v2]=1;
    }
}
void displayState(){
    int i,j;
    for(i=0;i<n;i++){
            cout<<state[i]<<" ";
    }
    cout<<"\n";
}
void initial(){
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
void bfs(int start){
    int i;
    insertQueue(start);
    state[start]=WAITING;
    while(!isEmptyQueue()){
        start=deletequeue();

        state[start]=VISITED;

        cout<<"\n"<<start<<" "<<label[start];

        for(i=0;i<n;i++){
            if(adj[start][i]==1 && state[i]==INITIAL){
                insertQueue(i);
                state[i]=WAITING;
            }
        }
    }
    cout<<"\n";
}
void bfsTraversal(){
    int i,start,components=1;
    for(i=0;i<n;i++){
        state[i]=INITIAL;
    }
    components++;
    //co1ut<<"Initial State:";
    //displayState();
    bfs(0);
    for(start=0;start<n;n++){
        if(state[start]==INITIAL){
            components=0;
            break;
        }
    }
    cout<<"Connected components: "<<components;
    if(components){
        cout<<"\nconnected";
    }
    else{
        cout<<"\nnot connected";
    }
}

int main(){
    cout<<"initial:\n";
    initial();
    output();

    //input weights
    input();
    cout<<"weights:\n";
    output();

    //bfs traverse
    bfsTraversal();

    return 0;
}
