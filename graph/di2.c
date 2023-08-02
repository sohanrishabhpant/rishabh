#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define v 3
int neighbourdis(int dis[v],bool set[v]){
    int min=1000;
    int min_index=-1;
        for (int i=0;i<v;i++){
        if (set[i]==false&&dis[i]<=min){
            min=dis[i];
            min_index=i;
        }
    }
    return min_index;
}
void print(int distance[v]){
    for (int i=0;i<v;i++){
        printf("%d ",distance[i]);
    }printf("\n");
}
void dijkstra(int graph[v][v],int src){
    bool set[v];
    int distance[v];
    for (int i=0;i<v;i++){
        distance[i]=10000;
        set[i]=false;
    }
    distance[0]=0;
    for (int i=0;i<v-1;i++){
    int u=neighbourdis(distance,set);
    set[u]=true;
    for (int x=0;x<v;x++){
    if (set[x]==false&&graph[u][x]&&distance[x]>=distance[u]+graph[u][x]&&distance[u]!=1000){
        distance[x]=distance[u]+graph[u][x];
    }
    }
}
print(distance);
}
int main(){
    int graph[3][3]={{0,3,7},{3,0,2},{1,2,4}};
    dijkstra(graph,0);
    }