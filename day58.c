// Problem Statement:
// Construct a binary tree from given preorder and inorder traversal arrays.

// Input Format:
// - First line contains integer N
// - Second line contains preorder traversal
// - Third line contains inorder traversal

// Output Format:
// - Print postorder traversal of constructed tree

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

struct node* build(int pre[],int in[],int start,int end,int* idx){
    if(start>end){
        return NULL;
    }

    struct node* root=create(pre[*idx]);
    (*idx)++;

    if(start==end){
        return root;
    }

    int pos=search(in,start,end,root->data);

    root->left=build(pre,in,start,pos-1,idx);
    root->right=build(pre,in,pos+1,end,idx);

    return root;
}

void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    int n,i;
    int pre[100],in[100];

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter preorder:\n");
    for(i=0;i<n;i++){
        scanf("%d",&pre[i]);
    }

    printf("Enter inorder:\n");
    for(i=0;i<n;i++){
        scanf("%d",&in[i]);
    }

    int idx=0;
    struct node* root=build(pre,in,0,n-1,&idx);

    printf("Postorder traversal:\n");
    postorder(root);

    return 0;
}