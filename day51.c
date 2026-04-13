// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers
// - Third line contains two node values

// Output Format:
// - Print the LCA value

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

struct node* insert(struct node* root,int val){
    if(root==NULL){
        return create(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}

struct node* lca(struct node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(n1<root->data && n2<root->data){
        return lca(root->left,n1,n2);
    }
    if(n1>root->data && n2>root->data){
        return lca(root->right,n1,n2);
    }
    return root;
}

int main(){
    int n,i,x,a,b;
    struct node* root=NULL;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&x);
        root=insert(root,x);
    }

    printf("Enter two nodes: ");
    scanf("%d%d",&a,&b);

    struct node* res=lca(root,a,b);

    if(res!=NULL){
        printf("LCA=%d",res->data);
    }

    return 0;
}