#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct node{
    int u;
    int v;
    int weight;
    int distance;
    struct node*next;
}node;
typedef struct graph{
    node**arr;
    int v;
}graph;
typedef struct heap{
    node*array;
    int size;
    int cap;
}heap;
void swap(node *a,node *b){
    node temp=*a;
    *a=*b;
    *b=temp;
}
node *makenode(int u,int v,int w,int s){
    node *temp=malloc(sizeof (node));
    temp->u=u;
    temp->v=v;
    temp->weight=w;
    temp->distance=0;
    temp->next=NULL;
    return temp;
}
heap*create_heap(int v){
    heap*temp=malloc(sizeof (heap));
    temp->size=0;
    temp->cap=v;
    temp->array=malloc(sizeof(node*)*v);
    return temp;
}
graph*create(int v){
    graph*temp=malloc(sizeof (graph));
    temp->v=v;
    temp->arr=(node**)malloc(sizeof (node*)*v);
    for (int i=0;i<v;i++){
        temp->arr[i]=NULL;
    }
    return temp;
}
graph*insert(graph*g,int u,int v,int w,int s){
    node *flag=g->arr[u];
    int var=0;
    if (var==0){
    if (flag==NULL){
        g->arr[u]=makenode(u,v,w,s);
    }
    else{
    while(flag->next!=NULL){
        flag=flag->next;
    }
    flag->next=makenode(u,v,w,s);}
    var=1;
    }
    if (var==1){
    node *flag1=g->arr[v];
    if (flag1==NULL){
        g->arr[v]=makenode(v,u,w,s);
    }
    else{
    while(flag1->next!=NULL){
        flag1=flag1->next;
    }
    flag1->next=makenode(v,u,w,s);
    }}
    return g;
}
heap*insert_node(heap*root,node data){
    int size=root->size;
    if (size==0){
        root->array[root->size]=data;
        root->size++;
        return root ;
    }
    else{
        root->array[root->size]=data;
        root->size++;
        int par=size-1/2;
        while(size>0&&root->array[size].weight<root->array[par].weight){
            swap(&root->array[size],&root->array[par]);
            par=size;
            size=par-1/2;
        }
        return root;
    }
}
void heapify(heap*root,int i,int n){
    int smallest=i;
    int left_child=2*i+1;
    int right_child=2*i+2;
    if (left_child<n&&root->array[i].weight>root->array[left_child].weight){
        smallest=left_child;
    }
    if (right_child<n&&root->array[smallest].weight>root->array[right_child].weight){
        smallest=right_child;
    }
    if (smallest!=i){
        swap(&root->array[smallest],&root->array[i]);
        heapify(root,smallest,n);
    }
}
node extract_min(heap*root,int n){
    node flag=root->array[0];
    swap(&root->array[0],&root->array[root->size-1]);
    root->size--;
    heapify(root,0,root->size);
    return flag;
}
void dijkstra(graph*g){
    heap*temp=create_heap(g->v);
    node flag;
    flag.u=0;
    flag.v=0;
    flag.weight=0;
    temp=insert_node(temp,flag);
    while(temp->size!=0){
        node ele=extract_min(temp,temp->size);
        node *arr=g->arr[ele.u];
        while(arr!=NULL){
            if (distance)
        }
    }

    
}
void print(graph*g){
    int v=g->v;
    for (int i=0;i<v;i++){
        node *temp=g->arr[i];
        while(temp!=NULL){
            printf(" u:%d v:%dans:%d ",temp->u,temp->v,temp->weight);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int u,v,w;
    node flag[n];
    graph*temp=create(n);
    for (int i=0;i<n;i++){
        scanf("%d %d %d",&u,&v,&w);
        // printf("%d %d %d\n",u,v,w);
        flag[i].u=u;
        flag[i].v=v;
        flag[i].weight=w;
        temp=insert(temp,u,v,w,);
    }
    print(temp);

}