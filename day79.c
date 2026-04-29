// Problem Statement
// Find shortest distances from source vertex in a weighted graph with non-negative weights.

// Input Format
// n m
// u v w
// source

// Output Format
// Distances to all vertices.

#include<stdio.h>
#define INF 100000

int main(){
    int n,m,i,u,v,w,src;
    scanf("%d%d",&n,&m);
    int adj[101][101];
    for(i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j]=INF;
        }
    }
    for(i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        adj[u][v]=w;
        adj[v][u]=w;
    }
    scanf("%d",&src);
    int dist[101],visited[101]={0};
    for(i=0;i<n;i++){
        dist[i]=INF;
    }
    dist[src]=0;
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
            if(adj[node][j]!=INF && !visited[j]){
                if(dist[node]+adj[node][j] < dist[j]){
                    dist[j]=dist[node]+adj[node][j];
                }
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",dist[i]);
    }
    return 0;
}