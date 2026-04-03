// Problem Statement:
// Perform inorder, preorder, and postorder traversals of a given binary tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)

// Output Format:
// - Print inorder, preorder, and postorder traversals

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create(int x){
    if(x==-1) return NULL;
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=x;
    n->left=n->right=NULL;
    return n;
}

struct node* build(int arr[],int n){
    if(n==0||arr[0]==-1) return NULL;

    struct node* root=create(arr[0]);
    struct node* q[1000];
    int front=0,rear=0;
    q[rear++]=root;
    int i=1;

    while(front<rear && i<n){
        struct node* temp=q[front++];

        if(i<n && arr[i]!=-1){
            temp->left=create(arr[i]);
            q[rear++]=temp->left;
        }
        i++;

        if(i<n && arr[i]!=-1){
            temp->right=create(arr[i]);
            q[rear++]=temp->right;
        }
        i++;
    }
    return root;
}

void inorder(struct node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct node* root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    struct node* root=build(arr,n);

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    return 0;
}