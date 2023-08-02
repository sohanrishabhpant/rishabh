#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define v 3
void print(int distance[v]){
    for (int i=0;i<v;i++){
        printf("%d ",distance[i]);
    }
}
int min_neighbour(int distance[v],bool known[v]){
    int min_index=-1;
    int min=1000;
    for (int i=0;i<v;i++){
        if (distance[i]<=min&&known[i]==false){
            min=distance[i];
            min_index=i;
        }
    }
    return min_index;
}
void dijsktra(int graph[v][v],int src){
    int distance[v];
    bool known[v];
    for (int i=0;i<v;i++){
        distance[i]=1000;
        known[i]=false;
    }
    distance[0]=0;
    for (int i=0;i<v-1;i++){
        int u=min_neighbour(distance,known);
        known[u]=true;
        for (int x=0;x<v;x++){
            if (distance[x]>distance[u]+graph[u][x]&&known[x]==false&&graph[u][x]&&distance[u]!=1000){
                distance[x]=distance[u]+graph[u][x];
            }
    }
}print(distance);
}
int main(){
    int graph[v][v]={{0,1,7},{2,3,4},{3,4,5}};
    dijsktra(graph,0);
}