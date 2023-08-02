#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node{
    int row_i;
    int col_i;
    int ans;
}node;
typedef struct heap{
    int size;
    int cap;
    node *arr;
}heap;
node *makenode (int r,int c,int ans){
    node *temp=malloc(sizeof (node));
    temp->row_i=r;
    temp->col_i=c;
    temp->ans=ans;
    return temp;
}
heap*create(int cap){
    heap*temp=malloc(sizeof (heap));
    temp->size=0;
    temp->cap=cap;
    temp->arr=(node*)malloc(sizeof (node));
    return temp;
}
heap*insert(heap*root,node ans){
    if (root->size==0){
        root->arr[root->size++]=ans;
        return ;
    }
    else{
        int size=root->size;
        root->arr[root->size++]=ans;
        int par=root->size-1/2;
        while(size>0&&root->arr[par].ans>root->arr[size].ans){
            swap(&root->arr[par],&root->arr[size]);
            size=par;
            par=size-1/2;
        }
    }
    return root;
}
void heapify(node*arr,int i,int n){
    int smallest=i;
    int left_child=2*i+1;
    int right_child=2*i+2;
    if (left_child<n&&arr[left_child].ans<arr[i].ans){
        smallest=left_child;
    }
    if (right_child<n&&arr[right_child].ans<arr[smallest].ans){
        smallest=right_child;
    }
}
int count(node**arr,int **a,int n,int m,heap*temp){
    node *temp=makenode(-1,-1,0);
    bool visited[n][m];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            visited[i][j]=false;
        }
    }       
    for (int i=0;i<m;i++){
        temp=insert(temp,arr[n-1][i]);
    }
    for (int i=0;i<n;i++){
        temp=insert(temp,arr[i][0]);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    int n,m;
    for (int i=0;i<t;i++){
        scanf("%d %d",&n,&m);
        int a[n][m];
        heap*temp=create(n*m);
        node **arr=malloc(sizeof (node*)*n);
        for (int i=0;i<n;i++){
            arr[i]=malloc(sizeof (node)*m);
        }
        for (int j=0;j<n;j++){
            for (int k=0;k<m;k++){
                arr[i][k].row_i=j;
                arr[i][k].col_i=k;
                scanf("%d",&a[i][j]);
                arr[i][k].ans=0;
            }
        }
        int min=count(a,arr,n,m,temp);
    printf("%d\n",min);
    }
}