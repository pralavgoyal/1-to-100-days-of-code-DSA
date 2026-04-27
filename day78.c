// Problem Statement
// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

// Input Format
// n m
// u v w
// ...

// Output Format
// Total weight of MST.

#include<stdio.h>
#define INF 100000

int main(){
    int n,m,i,u,v,w;

    scanf("%d%d",&n,&m);

    int adj[101][101];

    for(i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adj[i][j]=INF;
        }
    }

    for(i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        adj[u][v]=w;
        adj[v][u]=w;
    }

    int visited[101]={0};
    int minEdge[101];

    for(i=1;i<=n;i++){
        minEdge[i]=INF;
    }
    minEdge[1]=0;
    int total=0;
    for(i=1;i<=n;i++){
        int min=INF,node=-1;
        for(int j=1;j<=n;j++){
            if(!visited[j] && minEdge[j]<min){
                min=minEdge[j];
                node=j;
            }
        }
        visited[node]=1;
        total+=min;
        for(int j=1;j<=n;j++){
            if(!visited[j] && adj[node][j] < minEdge[j]){
                minEdge[j]=adj[node][j];
            }
        }
    }
    printf("%d",total);
    return 0;
}