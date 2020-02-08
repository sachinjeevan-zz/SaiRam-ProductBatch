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
    if(root==NULL)
        return 0;
    else
    {
        return root->height;
    }
    
}
int getBalance(struct Node* root){
    if(root==NULL)
        return 0;
    else{
        return getHeight(root->left)-getHeight(root->right);
    }
}
struct Node* LeftRotation(struct Node* root){
    struct Node* temp = root->right;
    struct Node* x = temp->left;
    temp->left = root;
    root->right = x;
    root=temp;
    if(root->left!=NULL)
    root->left->height = 1+max(getHeight(root->left->left),getHeight(root->left->right));
    if(root->right!=NULL)
    root->right->height = 1+max(getHeight(root->right->left),getHeight(root->right->right));
    root->height = 1+max(getHeight(root->left),getHeight(root->right));
    return root;
}
struct Node* RightRotation(struct Node* root){
    struct Node* temp = root->left;
    struct Node* x = temp->right;
    temp->right = root;
    root->left = x;
    root = temp;
    if(root->left!=NULL)
    root->left->height = 1+max(getHeight(root->left->left),getHeight(root->left->right));
    if(root->right!=NULL)
    root->right->height = 1+max(getHeight(root->right->left),getHeight(root->right->right));
    root->height = 1+max(getHeight(root->left),getHeight(root->right));
    return root;
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
    if(balance>1 && data<root->left->data){
        //LL
        root=RightRotation(root);
    }
    else if(balance>1 && data>root->left->data){
        //LR
        root->left = LeftRotation(root->left);
        root = RightRotation(root);
    }
    else if(balance<-1 && data>root->right->data){
        //RR
        root = LeftRotation(root);
    }
    else if(balance<-1 && data<root->right->data){
        //RL
        root->right = RightRotation(root->right);
        root = LeftRotation(root);
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