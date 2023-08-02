#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    int weight;
    struct node*next;
}node;
typedef struct graph{
    node **adj;
    int v;
}graph;

typedef struct heap{
    int size;
    int cap;
    node *arr;
}heap;

node *makenode(int data,int weight){
    node *temp=malloc(sizeof (node));
    temp->data=data;
    temp->next=NULL;
    temp->weight=weight;
    return temp;
}
graph*create(int v){
    graph*temp=malloc(sizeof (graph));
    temp->v=v;
    temp->adj=malloc(sizeof (node*)*v);
    for (int i=0;i<temp->v;i++){
        temp->adj[i]=makenode(i+1,0);
    }
    return temp;
}
heap*create_h(int v){
    heap*temp=malloc(sizeof (heap));
    temp->cap=v;
    temp->size=0;
    temp->arr=malloc(sizeof (node)*v);
    return temp;
}
graph* insert(graph*g,int u,int v,int w){
    node *temp=g->adj[u-1];
    node *flag=makenode (v,w);
    flag->next=temp->next;
    temp->next=flag;
    node *temp1=g->adj[v-1];
    node *flag1=makenode (u,w);
    flag1->next=temp1->next;
    return temp;
}
int * relax(graph*g,int u,int v){
    int *ans=malloc(sizeof (int)*g->v);
    int count=0;
    int flag=0;
    node *temp=g->adj[flag];
    ans[count++]=g->adj[flag]->weight;
    while(temp!=NULL){

    }

}
int main(){
    int n;
    scanf("%d",&n);

}