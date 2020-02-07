#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left,*right;
    int height;
};
struct Node* newNode(int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->left = NULL;
    new->right = NULL;
    new->data = data;
    new->height =1;
    return new;
}
void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int max(int a,int b){
    return a>b?a:b;
}
int getHeight(struct Node* root){
    if(root==NULL)return 0;
    else return root->height;
}
int getBalance(struct Node* root){
    if(root==NULL) return 0;
    else return getHeight(root->left)-getHeight(root->right);
}
struct Node* insert(struct Node* root,int data){
    if(root == NULL){
        return newNode(data);
    }
    else if(data > root->data){
        root->right = insert(root->right,data);
    }
    else{
        root->left = insert(root->left,data);
    }
    root->height = 1+max(getHeight(root->left),getHeight(root->right));
    int balance = getBalance(root);
    if(balance<-1 && data>root->right->data){
        struct Node* temp = root->right;
        struct Node* x = temp->left;
        temp->left = root;
        root->right = x;
        root = temp;
        root->left->height = max(getHeight(root->left->left),getHeight(root->left->right));
        root->right->height = max(getHeight(root->right->left),getHeight(root->right->right));
        root->height = max(getHeight(root->left),getHeight(root->right));
    }
    else if(balance<-1 && data<root->right->data){
        //RL
        struct Node* temp = root->right;
        struct Node* x = temp->left;
        temp->left = x->left;
        root->right = x->right;
        x->left = root;
        x->right = temp;
        root = x;
        root->left->height = max(getHeight(root->left->left),getHeight(root->left->right));
        root->right->height = max(getHeight(root->right->left),getHeight(root->right->right));
        root->height = max(getHeight(root->left),getHeight(root->right));
    }
    else if(balance>1 && data<root->left->data){
        struct Node* temp = root->left;
        struct Node* x = temp->right;
        temp->right = root;
        root->left = x;
        root = temp;
         root->left->height = max(getHeight(root->left->left),getHeight(root->left->right));
        root->right->height = max(getHeight(root->right->left),getHeight(root->right->right));
        root->height = max(getHeight(root->left),getHeight(root->right));
    }
    else if(balance>1 && data > root->left->data){
        //LR
        struct Node* temp = root->left;
        struct Node* x = temp->right;
        temp->right = x->left;
        root->left = x->right;
        temp->right = x->left;
        x->left = temp;
        x->right = root;
        root = x;
        root->left->height = max(getHeight(root->left->left),getHeight(root->left->right));
        root->right->height = max(getHeight(root->right->left),getHeight(root->right->right));
        root->height = max(getHeight(root->left),getHeight(root->right));
        
    }
    return root;
}
int main(){
    struct Node* root = NULL;
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        root = insert(root,x);
    }
    inorder(root);
}