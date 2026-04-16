// Problem Statement:
// Print the nodes visible when the binary tree is viewed from the right side.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print right view nodes

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

    struct node* q[100];
    int front=0,rear=0;

    q[rear++]=root;

    printf("Right View:\n");

    while(front<rear){
        int size=rear-front;

        for(i=0;i<size;i++){
            struct node* temp=q[front++];

            if(i==size-1){
                printf("%d ",temp->data);
            }

            if(temp->left) q[rear++]=temp->left;
            if(temp->right) q[rear++]=temp->right;
        }
    }

    return 0;
}