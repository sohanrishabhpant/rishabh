#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define v 3
int neighbourdis(int dis[v],bool known[v],int parent[v]){
    int min=1000;
    int min_index=-1;
    for (int i=0;i<v;i++){
        if (known[i]==false&&dis[i]<=min){
            min=dis[i];
            min_index=i;
        }
    }
}
void  print(int parent[v],int graph[v][v]){
    for (int i=1;i<v;i++){
        printf("%d-%d %d\n",parent[i],i,graph[i][parent[i]]);
    }
}
void mst(int graph[v][v],int src){
    int distance[v];
    bool known[v];
    int parent[v];
    for (int i=0;i<v;i++){
        known[i]=false;
        distance[i]=1000;
    }
    parent[0]=-1;
    for (int i=0;i<v-1;i++){
        int u=neighbourdis(distance,known,parent);
        known[u]=true;
        for (int x=0;x<v;x++){
            if (graph[u][x]&&known[x]==false&&graph[u][x]<distance[x]){
                distance[x]=graph[u][x];
                parent[x]=u;
            }
        }
    }print(parent,graph);
}
int main(){
    int graph[v][v]={{0,1,1},{1,2,3},{3,4,5}};
    mst(graph,0);
}