// Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include<stdio.h>
#include<stdlib.h>
#define INF 100000

int main(){
    int n,m,i,u,v,w,s;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int adj[100][100];

    for(i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j]=0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d",&m);

    printf("Enter edges (u v w):\n");
    for(i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        adj[u][v]=w;
    }

    printf("Enter source: ");
    scanf("%d",&s);

    int dist[100],visited[100];

    for(i=0;i<n;i++){
        dist[i]=INF;
        visited[i]=0;
    }

    dist[s]=0;

    for(i=0;i<n;i++){
        int min=INF,node=-1;

        for(int j=0;j<n;j++){
            if(!visited[j] && dist[j]<min){
                min=dist[j];
                node=j;
            }
        }
        if(node==-1) break;
        visited[node]=1;
        for(int j=0;j<n;j++){
            if(adj[node][j]!=0 && !visited[j]){
                if(dist[node]+adj[node][j] < dist[j]){
                    dist[j]=dist[node]+adj[node][j];
                }
            }
        }
    }
    printf("Shortest distances:\n");
    for(i=0;i<n;i++){
        printf("%d -> %d = %d\n",s,i,dist[i]);
    }
    return 0;
}