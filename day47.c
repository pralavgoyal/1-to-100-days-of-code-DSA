// Problem: Height of Binary Tree

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

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

int height(struct node* root){
    if(root==NULL) return 0;
    int l=height(root->left);
    int r=height(root->right);
    return (l>r?l:r)+1;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    struct node* root=build(arr,n);

    printf("%d",height(root));

    return 0;
}