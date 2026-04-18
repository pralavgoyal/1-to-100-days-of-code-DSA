// Problem Statement:
// Convert a binary tree into its mirror image by swapping left and right children at every node.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print inorder traversal of mirrored tree

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

struct node* build(int arr[],int i,int n){
    if(i>=n || arr[i]==-1){
        return NULL;
    }
    struct node* root=create(arr[i]);
    root->left=build(arr,2*i+1,n);
    root->right=build(arr,2*i+2,n);
    return root;
}

void mirror(struct node* root){
    if(root==NULL){
        return;
    }
    struct node* temp=root->left;
    root->left=root->right;
    root->right=temp;

    mirror(root->left);
    mirror(root->right);
}

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main(){
    int n,i;
    int arr[100];

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter level order (-1 for NULL):\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    struct node* root=build(arr,0,n);

    mirror(root);

    printf("Inorder of mirrored tree:\n");
    inorder(root);

    return 0;
}