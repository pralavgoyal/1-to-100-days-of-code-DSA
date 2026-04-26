// Problem Statement
// Using DFS or BFS, count number of connected components.

// Input Format
// n m
// edges

// Output Format
// Number of connected components.

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

    struct node* temp=adj[v];
    while(temp!=NULL){
        if(!visited[temp->data]){
            dfs(temp->data);
        }
        temp=temp->next;
    }
}

int main(){
    int n,m,i,u,v;
    printf("Enter vertices and edges: ");
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        adj[i]=NULL;
        visited[i]=0;
    }
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
    int count=0;
    for(i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
            count++;
        }
    }
    printf("Connected components: %d",count);
    return 0;
}