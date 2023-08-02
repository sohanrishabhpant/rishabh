#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define v 3
void print(int parent[v],int graph[v][v]){
    for(int i=1;i<v;i++){
        printf("%d-%d %d\n",parent[i],i,graph[i][parent[i]]);
    }
}
int minneighbour(int distance[v],bool known[v]){
    int min=1000;
    int min_index=-1;
    for (int i=0;i<v;i++){
        if (known[i]==false&&distance[i]<=min){
            min=distance[i];
            min_index=i;
        }
    }
    return min_index;
}
void mst(int graph[v][v],int src){
    int parent[v];
    bool known[v];
    int distance[v];
    for (int i=0;i<v;i++){
        distance[i]=1000;
        known[i]=false;
    }
    parent[0]=-1;
    distance[0]=0;
    for(int i=0;i<v-1;i++){
        int u=minneighbour(distance,known);
        known[u]=true;
        for (int x=0;x<v;x++){
            if (graph[u][x]&&distance[x]>=graph[u][x]&&known[x]==false){
                distance[x]=graph[u][x];
                parent[x]=u;
            }
        }
    }
     print(parent,graph);
}
int main(){
    int graph[v][v]={{0,1,1},{1,2,3},{3,4,5}};
    mst(graph,0);
}