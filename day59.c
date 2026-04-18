// Problem Statement:
// Construct a binary tree from given inorder and postorder traversal arrays.

// Input Format:
// - First line contains integer N
// - Second line contains inorder traversal
// - Third line contains postorder traversal

// Output Format:
// - Print preorder traversal of constructed tree

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create(int val){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

int search(int in[],int start,int end,int val){
    for(int i=start;i<=end;i++){
        if(in[i]==val){
            return i;
        }
    }
    return -1;
}

struct node* build(int in[],int post[],int start,int end,int* idx){
    if(start>end){
        return NULL;
    }

    struct node* root=create(post[*idx]);
    (*idx)--;

    if(start==end){
        return root;
    }

    int pos=search(in,start,end,root->data);

    root->right=build(in,post,pos+1,end,idx);
    root->left=build(in,post,start,pos-1,idx);

    return root;
}

void preorder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    int n,i;
    int in[100],post[100];

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter inorder:\n");
    for(i=0;i<n;i++){
        scanf("%d",&in[i]);
    }

    printf("Enter postorder:\n");
    for(i=0;i<n;i++){
        scanf("%d",&post[i]);
    }

    int idx=n-1;
    struct node* root=build(in,post,0,n-1,&idx);

    printf("Preorder traversal:\n");
    preorder(root);

    return 0;
}