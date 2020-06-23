//recursive
#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
    struct node *left;
    int info;
    struct node *right;
};

void insert(struct node **root, int item){
    if(*root == NULL){
        *root = (struct node *) malloc (sizeof(struct node));
        (*root)->info = item;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else{
        if(item < (*root) -> info){
            insert( &((*root)->left), item);
        }
        else{
            insert( &((*root)->right), item);
        }
    }
}

void preorder(struct node *parent){
    if(parent != NULL){
        cout<< parent->info<<" ";
        preorder(parent->left);
        preorder(parent->right);
    }
}

void inorder(struct node *parent){
    if(parent != NULL){
        inorder(parent->left);
        cout<< parent->info<<" ";
        inorder(parent->right);
    }
}
void postorder(struct node *parent){
    if(parent != NULL){
        postorder(parent->left);
        postorder(parent->right);
        cout<< parent->info<<" ";
    }
}
struct node *min(struct node *temp){
    if(temp==NULL){
        return NULL;
    }
    else if(temp->left==NULL){
        return temp;
    }
    else{
        return min(temp->left);
    }
}
struct node *max(struct node *temp){
    if(temp==NULL){
        return NULL;
    }
    else if(temp->right==NULL){
        return temp;
    }
    else{
        return max(temp->right);
    }
}
int height(struct node *temp){
  int l,r;
  if(temp==NULL){
    return 0;
  }
  l=height(temp->left);
  r=height(temp->right);
  if(l>r){
    return 1+l;
  }
  else{
    return 1+r;
  }
}

struct node *del(struct node *parent, int item){
    struct node *temp, *temp1;
    if(parent==NULL){
        cout<<item<<" not found\n";
        return parent;
    }
    if(item < parent->info){
        parent->left=del(parent->left,item);
    }
    else if(item > parent->info){
        parent->right=del(parent->right,item);
    }
    else{
        if(parent->left != NULL && parent->right != NULL){ //2 child
            temp=parent->right;
            while(temp->left){
                temp=temp->left;
            }
            parent->info=temp->info;
            parent->right=del(parent->right, temp->info);
        }
        else{
            temp1=parent;
            if(parent->left != NULL){      //1  left child
                parent=parent->left;
            }
            else if(parent->right != NULL){//1  right child
                parent=parent->right;
            }
            else{                        // no child
                parent = NULL;
            }
            free(temp1);
        }
    }
    return parent;
}
int totalNodes(struct node *root){
    if(root == NULL){
        return 0;
    }
    else{
        return totalNodes(root->left)+ totalNodes(root->right)+1;
    }
}
 void mirror(struct node *root){
    struct node *temp;
    if(root!=NULL){
        mirror(root->left);
        mirror(root->right);

        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
 }


struct node *search(struct node *root, int item){
    if(root==NULL){
        return NULL;
    }
    else if(item < root->info){
        return search(root->left, item);
    }
    else if(item > root->info){
        return search(root->right, item);
    }
    else{
        return root;
    }
}
int main(){
    int choice,key;
    struct node *root=NULL, *temp; //create tree
    while(1){
        cout<<"\n-----BINARY SEARCH OPERATION-----\n";
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. Height of the tree\n";
        cout<<"4. Min/Max element\n";
        cout<<"5. Search element\n";
        cout<<"6. All views\n";
        cout<<"7. Total Nodes \n";
        cout<<"8. Make mirror\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice\n";
        cout<<"---------------------------------\n";
        cin>>choice;
        switch(choice){
        case 1:
            int num,i;
            cout<<"\nNumber if keys to insert: ";
            cin>>num;
            for(i=0;i<num;i++){
                cin>>key;
                insert(&root,key);
            }
            break;
        case 2:
            cout<<"\nItem to delete: ";
            cin>>key;
            root=del(root,key);
            break;
        case 3:
            cout<<"\nHeight : "<< height(root);
            break;
        case 4:
            cout<<"\nMin: " << min(root)->info;
            cout<<"\nMax: " <<max(root)->info;
            break;
        case 5:
            cout<<"\nItem to search: ";
            cin>>key;
            temp = search(root,key);
            if(temp != NULL){
                cout<<key<<" found";
            }
            else{
                cout<<key<<" not found";
            }
            break;
        case 6:
            cout<<"-----All Views------\n";
            cout<<"\nPreorder: ";
            preorder(root);
            cout<<"\nInorder: ";
            inorder(root);
            cout<<"\nPostorder: ";
            postorder(root);
            break;
        case 7:
            cout<<"\nTotal nodes: "<<totalNodes(root);
            break;
        case 8:
            mirror(root);
            break;
        case 0:
            exit(1);
        default:
            cout<<"Wrong choice!\n";
        }
    }
    return 0;
}
