
#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include <cstdlib>

using namespace std;

#define MAX 10

int stack[MAX];
int top=-1;


int isFull(){
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}

void push(int item){
    if(isFull()){
        cout<<"\nOverflow";
        return;
    }
    top += 1;
    stack[top]=item;
}
int pop(){
    int item;
    if(isEmpty()){
        cout<<"\nUnderflow";
        exit(1);
    }
    item=stack[top];
    top -= 1;
    return item;
}
int peek(){
    if(isEmpty()){
        cout<<"\nUnderflow";
        exit(1);
    }
    return stack[top];
}

void display(){
    int i;
    if(isEmpty()){
        cout<<"\nStack empty";
        return;
    }
    cout<<"\nStack: ";
    for(i=top;i>=0;i--){
        cout<<stack[i]<<" ";
    }
}

int main(){
  int choice;
  while(1){
    cout<<"\n_____MENU_____\n";
    cout<<"1.Push\n";
    cout<<"2.Pop\n";
    cout<<"3.Peek Top\n";
    cout<<"4.Display All\n";
    cout<<"5.Quit\n";
    cout<<"Enter choice: ";
    cin>>choice;

    int item;
    switch(choice){
    case 1:
        cout<<"\nEnter item to push: ";
        cin>>item;
        push(item);
        break;
    case 2:
        item=pop();
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
