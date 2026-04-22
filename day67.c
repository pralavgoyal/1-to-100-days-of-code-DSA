// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* adj[100];
int visited[100];
int stack[100];
int top=-1;

void dfs(int v){
    visited[v]=1;

    struct node* temp=adj[v];
    while(temp!=NULL){
        if(!visited[temp->data]){
            dfs(temp->data);
        }
        temp=temp->next;
    }

    stack[++top]=v;
}

int main(){
    int n,m,i,u,v;

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
    }

    for(i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    printf("Topological Order:\n");
    while(top!=-1){
        printf("%d ",stack[top--]);
    }

    return 0;
}