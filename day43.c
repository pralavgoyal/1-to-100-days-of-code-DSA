// Problem Statement:
// Construct a Binary Tree from the given level-order traversal.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers (-1 represents NULL)

// Output Format:
// - Print inorder traversal of the constructed tree

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

struct node* buildTree(int arr[],int n){
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

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    struct node* root=buildTree(arr,n);
    inorder(root);
    return 0;
}