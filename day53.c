// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct qnode{
    struct node* n;
    int hd;
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

    struct qnode q[100];
    int front=0,rear=0;

    int col[200][100],count[200]={0};

    q[rear].n=root;
    q[rear].hd=100;
    rear++;

    while(front<rear){
        struct node* temp=q[front].n;
        int hd=q[front].hd;
        front++;

        if(temp==NULL) continue;

        col[hd][count[hd]++]=temp->data;

        if(temp->left){
            q[rear].n=temp->left;
            q[rear].hd=hd-1;
            rear++;
        }
        if(temp->right){
            q[rear].n=temp->right;
            q[rear].hd=hd+1;
            rear++;
        }
    }

    printf("Vertical Order Traversal:\n");
    for(i=0;i<200;i++){
        if(count[i]!=0){
            for(int j=0;j<count[i];j++){
                printf("%d ",col[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}