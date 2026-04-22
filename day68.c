// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* adj[100];
int indegree[100];

int main(){
    int n,m,i,u,v;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        adj[i]=NULL;
        indegree[i]=0;
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

        indegree[v]++;
    }

    int q[100],front=0,rear=0;

    for(i=0;i<n;i++){
        if(indegree[i]==0){
            q[rear++]=i;
        }
    }

    printf("Topological Order:\n");

    int count=0;

    while(front<rear){
        int node=q[front++];
        printf("%d ",node);
        count++;

        struct node* temp=adj[node];
        while(temp!=NULL){
            int v=temp->data;
            indegree[v]--;

            if(indegree[v]==0){
                q[rear++]=v;
            }

            temp=temp->next;
        }
    }

    if(count!=n){
        printf("\nCycle detected");
    }

    return 0;
}