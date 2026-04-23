// Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

// Input:
// - n vertices
// - m edges (u,v,w)

// Output:
// - Shortest distances OR NEGATIVE CYCLE

#include<stdio.h>
#define INF 100000

struct edge{
    int u,v,w;
};

int main(){
    int n,m,i,j,s;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter number of edges: ");
    scanf("%d",&m);

    struct edge e[100];

    printf("Enter edges (u v w):\n");
    for(i=0;i<m;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }

    printf("Enter source: ");
    scanf("%d",&s);

    int dist[100];

    for(i=0;i<n;i++){
        dist[i]=INF;
    }

    dist[s]=0;

    for(i=0;i<n-1;i++){
        for(j=0;j<m;j++){
            int u=e[j].u;
            int v=e[j].v;
            int w=e[j].w;

            if(dist[u]!=INF && dist[u]+w < dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }

    int cycle=0;

    for(j=0;j<m;j++){
        int u=e[j].u;
        int v=e[j].v;
        int w=e[j].w;
        if(dist[u]!=INF && dist[u]+w < dist[v]){
            cycle=1;
            break;
        }
    }
    if(cycle){
        printf("NEGATIVE CYCLE\n");
    }
    else{
        printf("Shortest distances:\n");
        for(i=0;i<n;i++){
            printf("%d -> %d = %d\n",s,i,dist[i]);
        }
    }
    return 0;
}