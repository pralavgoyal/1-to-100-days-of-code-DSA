// Problem Statement:
// Check whether a given binary tree is symmetric around its center.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print YES if symmetric, otherwise NO

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

int isMirror(struct node* t1,struct node* t2){
    if(t1==NULL && t2==NULL){
        return 1;
    }
    if(t1==NULL || t2==NULL){
        return 0;
    }
    if(t1->data!=t2->data){
        return 0;
    }
    return isMirror(t1->left,t2->right) && isMirror(t1->right,t2->left);
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

    if(isMirror(root,root)){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;
}