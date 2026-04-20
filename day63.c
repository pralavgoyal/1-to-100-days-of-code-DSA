// Problem: Perform DFS starting from a given source vertex using recursion.

// Input:
// - n
// - adjacency list
// - starting vertex s

// Output:
// - DFS traversal order

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* adj[100];
int visited[100];

void dfs(int v){
    visited[v]=1;
    printf("%d ",v);

    struct node* temp=adj[v];
    while(temp!=NULL){
        if(!visited[temp->data]){
            dfs(temp->data);
        }
        temp=temp->next;
    }
}

int main(){
    int n,m,i,u,v,s;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        adj[i]=NULL;
        visited[i]=0;
    }

    printf("Enter number of edges: ");
    scanf("%d",&m);

    printf("Enter edges (u v):\n");
    for(i=0;i<m;i++){
        scanf("%d%d",&u,&v);

        struct node* new1=(struct node*)malloc(sizeof(struct node));
        new1->data=v;
        new1->next=adj[u];
        adj[u]=new1;

        struct node* new2=(struct node*)malloc(sizeof(struct node));
        new2->data=u;
        new2->next=adj[v];
        adj[v]=new2;
    }

    printf("Enter starting vertex: ");
    scanf("%d",&s);

    printf("DFS traversal:\n");
    dfs(s);

    return 0;
}