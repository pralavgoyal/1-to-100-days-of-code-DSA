// Problem: Detect cycle in directed graph using DFS and recursion stack.

// Output:
// - YES if cycle exists

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* adj[100];
int visited[100];
int recStack[100];

int dfs(int v){
    visited[v]=1;
    recStack[v]=1;

    struct node* temp=adj[v];
    while(temp!=NULL){
        int u=temp->data;

        if(!visited[u]){
            if(dfs(u)){
                return 1;
            }
        }
        else if(recStack[u]){
            return 1;
        }

        temp=temp->next;
    }

    recStack[v]=0;
    return 0;
}

int main(){
    int n,m,i,u,v;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        adj[i]=NULL;
        visited[i]=0;
        recStack[i]=0;
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

    int cycle=0;

    for(i=0;i<n;i++){
        if(!visited[i]){
            if(dfs(i)){
                cycle=1;
                break;
            }
        }
    }

    if(cycle) printf("YES");
    else printf("NO");

    return 0;
}