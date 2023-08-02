#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next;
}node;
typedef struct graph{
    node **adj;
    int v;
}graph;
typedef struct heap{
    int size;
    int cap;
    int *arr;
}heap;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
node *makenode(int data){
    node *temp=malloc(sizeof (node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
graph*create_g(int v){
    graph*temp=malloc(sizeof (graph));
    temp->v=v;
    temp->adj=(node**)malloc(sizeof (node*)*v);
    for(int i=0;i<v;i++){
        temp->adj[i]=makenode(i+1);
    }
    return temp;
}
heap*create_h(int v){
    heap*temp=malloc(sizeof(heap));
    temp->cap=v;
    temp->arr=malloc(sizeof (int)*v);
    temp->size=0;
    return temp;
}
heap*insert_h(heap*root,int data){
    int s=root->size;
    if (root->size==0){
        root->arr[root->size++]=data;
        return root;
    }
    else{
        root->arr[root->size++]=data;
        int par=(s-1)/2;
        while(s>0&&root->arr[par]>root->arr[s]){
            swap(&root->arr[par],&root->arr[s]);
            s=par;
            par=(s-1)/2;
        }
    }
    return root;
}
void heapify(heap*root,int i,int n){
    int left=2*i+1;
    int right=2*i+2;
    int smallest=i;
    if (left<n&&root->arr[left]<root->arr[i]){
        smallest=left;
    }
    if (right<n&&root->arr[right]<root->arr[smallest]){
        smallest=right;
    }
    if (smallest!=i){
        swap(&root->arr[i],&root->arr[smallest]);
        heapify(root,smallest,n);
    }
}
int extract_min(heap*root){
    int s=root->size;
    int temp=root->arr[0];
    swap(&root->arr[0],&root->arr[root->size-1]);
    root->size--;
    heapify(root,0,root->size);
    return temp;
}
graph*insert(graph*g,int u,int v){
    node *temp=g->adj[u-1];
    node *flag=makenode(v);
    flag->next=temp->next;
    temp->next=flag;
    node *temp1=g->adj[v-1];
    node *flag1=makenode(u);
    flag1->next=temp1->next;
    temp1->next=flag1;
    return g;
    
}
void print(graph*g){
    for (int i=0;i<g->v;i++){
        node *temp=g->adj[i];
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }printf("\n");
    }
}
void print_h(heap*root,int n){
    for (int i=0;i<n;i++){
        printf("%d",root->arr[i]);
    }
}
int* traversal(graph*g,heap*root){
    bool visited[g->v];
    for (int i=0;i<g->v;i++){
        visited[i]=false;
    }
    int flag=1;
    int count=0;
    int *ans=malloc(sizeof (int)*g->v);
    ans[count++]=flag;
    while(count<g->v){
        node *temp=g->adj[flag-1];
        visited[flag-1]=true;
        while(temp!=NULL){
            if (visited[temp->data-1]==false){
                visited[temp->data-1]=true;
                root=insert_h(root,temp->data);
            }
            temp=temp->next;
        }
        flag=extract_min(root);
        ans[count++]=flag;
    }
    return ans;
}
int main(){
    int n,m;
    int u,v;
    scanf("%d%d",&n,&m);
    heap*temp=create_h(n);
    graph*g=create_g(n);    
    for (int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        g=insert(g,u,v);
    }
    int *ans=traversal(g,temp);
    for (int i=0;i<n;i++){
        printf("%d ",ans[i]);
    }printf("\n");
//     print(g);

}