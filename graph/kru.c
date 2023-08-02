#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int comparator(const void *p1,const void *p2){
    const int *x[3]=p1;
    const int *y[3]=p2;
    return *x[2]-*y[2];
}
void makeset(int parent[],int rank[],int n){
    for (int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}
int findparent(int parent[],int component){
    if (parent[component]==component){
        return component;
    }
    return parent[component]=findparent(parent,parent[component]);
}
void union_by_sets(int u,int v,int parent[],int rank[],int n){
    u=findparent(parent,u);
    v=findparent(parent,v);
    if (rank[u]<rank[v]){
        parent[u]=v;
    }
    else if (rank[u]>rank[v]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}
