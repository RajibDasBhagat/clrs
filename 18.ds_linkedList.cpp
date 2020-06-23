#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include <cstdlib>

using namespace std;


struct node{
    int info;
    struct node *next;
};

int search(struct node *start, int item){
    struct node *current = start;
    int count=0;
    while(current!= NULL){
        if(current->info==item){
            return count+1;
        }
        count++;
        current=current->next;
    }
    return 0;
}

int countNode(struct node *start){
    struct node *current;
    current=start;
    int count=0;
    while(current!=NULL){
        count++;
        current=current->next;
    }
    return count;
}

void display(struct node *start){
        struct node *current;
        cout<<"\nList ";
        if(start==NULL){
            cout<<"is Empty!";
        }
        current=start;
        while(current != NULL){
            cout<<current->info<<" ";
            current = current -> next;
        }
        cout<<"\n\n";
}

struct node *atBegin(struct node *start, int item){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info=item;
    temp->next=start;

    start=temp;
    return start;
}

struct node *atEnd(struct node *start, int item){
    struct node *temp, *current;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info=item;
    current=start;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next=temp;
    temp->next=NULL;

    return start;
}

struct node *atLoc(struct node *start,int item,int loc){
    struct node *temp,*current;
    temp=(struct node *)malloc(sizeof(struct node));

    temp->info=item;
    if(loc==1){
        temp->next=start;
        start=temp;
        return start;
    }
    current=start;
    int i;
    for(i=0;i<loc-1 && current!=NULL;i++){
        current=current->next;
    }
    if(current==NULL){
        cout<<"\nNot enough Elements";
    }
    else{
        temp->next=current->next;
        current->next=temp;
    }
    return start;
}

struct node *create(struct node *start){
    int i,nodes,item;
    cout<<"\nNodes: ";
    cin>>nodes;

    start=NULL;
    if(nodes==NULL){
        return start;
    }
    cout<<"\n1st Item: ";
    cin>>item;
    start = atBegin(start,item);

    for(i=1;i<nodes;i++){
        cin>>item;
        start = atEnd(start,item);
    }

    return start;
}

struct node *reverse(struct node *start){
    struct node *prev, *curr, *next;
    prev=NULL;
    curr=start;
    while(curr != NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    start=prev;
    return start;
}

struct node *del(struct node *start,int item){
    struct node *temp,*current;
    if(start==NULL){
        cout<<"\nList is empty";
        return start;
    }
    if(start->info==item){ //first node
        temp=start;
        start=start->next;
        free(temp);
        return start;
    }
    current=start;
    while(current->next != NULL){
        if(current->next->info==item){
            temp=current->next;
            current->next=temp->next;
            free(temp);
            return start;
        }
        current=current->next;
    }
    cout<<"\nElement not found!";
    return start;
}
int main(){
  struct node *start=NULL;
  int choice;
  while(1){
    cout<<"\n_____MENU_____\n";
    cout<<"1.Create\n";
    cout<<"2.Display\n";
    cout<<"3.Count\n";
    cout<<"4.Search\n";
    cout<<"5.Insert at Begin\n";
    cout<<"6.Insert at End \n";
    cout<<"7.Insert at Location \n";
    cout<<"8.Delete\n";
    cout<<"9.Reverse\n";

    cout<<"12.Quit\n";
    cout<<"Enter choice: ";
    cin>>choice;

    int item,loc,count,index;
    switch(choice){
    case 1:
        start=create(start);
        break;
    case 2:
        display(start);
        break;
    case 3:
        count=countNode(start);
        cout<<"\nCount: "<<count;
        break;
    case 4:
        cout<<"\nItem to search:";
        cin>>item;
        index=search(start,item);
        cout<<"\nIndex: "<<index;
        break;
    case 5:
        cout<<"\nItem to insert at begin: ";
        cin>>item;
        start = atBegin(start,item);
        break;
    case 6:
        cout<<"\nItem to insert at End: ";
        cin>>item;
        start = atEnd(start,item);
        break;
    case 7:
        cout<<"\nItem to Location: ";
        cin>>item;
        cout<<"\nLocation: ";
        cin>>loc;
        start = atLoc(start,item,loc);
        break;
    case 8:
        cout<<"\nEnter item to delete: ";
        cin>>item;
        start = del(start,item);
        display(start);
        break;
    case 9:
        cout<<"\nReversed: ";
        start=reverse(start);
        display(start);
        break;
    case 12:
        exit(0);
    default:
        cout<<"\nwrong choice";
    }

  }
  return 0;
}
