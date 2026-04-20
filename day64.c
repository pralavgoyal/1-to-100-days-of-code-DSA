// Problem: Perform BFS from a given source using queue.

// Input:
// - n
// - adjacency list
// - source s

// Output:
// - BFS traversal order

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* adj[100];
int visited[100];

void bfs(int s){
    int q[100],front=0,rear=0;

    visited[s]=1;
    q[rear++]=s;

    while(front<rear){
        int v=q[front++];
        printf("%d ",v);

        struct node* temp=adj[v];
        while(temp!=NULL){
            if(!visited[temp->data]){
                visited[temp->data]=1;
                q[rear++]=temp->data;
            }
            temp=temp->next;
        }
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

    printf("Enter source: ");
    scanf("%d",&s);

    printf("BFS traversal:\n");
    bfs(s);

    return 0;
}