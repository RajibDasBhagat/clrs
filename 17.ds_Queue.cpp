
#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include <cstdlib>

using namespace std;

#define MAX 10

int queue[MAX];
int front=-1;
int rear=-1;


int isFull(){
    if(rear==MAX-1)
        return 1;
    else
        return 0;

}
int isEmpty(){
    if(front==-1 || (front==rear+1))
        return 1;
    else
        return 0;
}

void insert(int item){
    if(isFull()){
        cout<<"\n Overflow";
        return;
    }
    if(front==-1){
        front += 1;
    }
    rear += 1;
    queue[rear]=item;
}
int del(){
    int item;
    if(isEmpty()){
        cout<<"\nUnderflow";
        exit(1);
    }
    item = queue[front];
    front += 1;
    return item;
}
int peek(){
    if(isEmpty()){
        cout<<"\nUnderflow";
        exit(1);
    }
    return queue[front];
}
void display(){
    int i;
    if(isEmpty()){
        cout<<"\nEmpty";
        return;
    }
    cout<<"\nQueue: ";
    for(i=front;i<=rear;i++){
        cout<<queue[i]<<" ";
    }
}

int main(){
  int choice;
  while(1){
    cout<<"\n_____MENU_____\n";
    cout<<"1.Insert\n";
    cout<<"2.Delete\n";
    cout<<"3.Peek\n";
    cout<<"4.Display All\n";
    cout<<"5.Quit\n";
    cout<<"Enter choice: ";
    cin>>choice;

    int item;
    switch(choice){
    case 1:
        cout<<"\nEnter item to push: ";
        cin>>item;
        insert(item);
        break;
    case 2:
        item=del();
        cout<<"\npopped: "<<item;
        break;
    case 3:
        item=peek();
        cout<<"\nTop: "<<item;
        break;
    case 4:
        display();
        break;
    case 5:
        exit(1);
    default:
        cout<<"\nwrong choice";
    }
  }
  return 0;
}

