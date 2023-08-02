#include"heap.h"

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
heap* create(int cap){
    heap* temp=malloc(sizeof (heap));
    temp->size=0;
    temp->cap=cap;
    temp->arr=malloc(sizeof (int)*cap);
    return temp;
}
void heapify(heap *a,int i,int n){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&a->arr[i]<a->arr[left]){
        largest=left;
    }
    if (right<n&&a->arr[right]>a->arr[largest]){
        largest=right;
    }
    if (largest!=i){
        swap(&a->arr[i],&a->arr[largest]);
        heapify(a,largest,n);
    }
}
void heap_insert(heap*root, int val) {
    if (root->size<0){
        return;
    }
    if (root->size == 0) {
        root->arr[0] = val;
        (root->size)++;
        return;
    }
        else{
    root->arr[root->size] =val;
    root->size++;
    int i = root->size - 1;
    int parent = (i - 1) / 2;

    while (i > 0 && root->arr[parent] > root->arr[i]) {
        swap(&root->arr[parent], &root->arr[i]);
        i = parent;
        parent = (i - 1) / 2;
    }
}}

void heap_sort(heap *a,int n){
    for (int i=n-1/2;i>=0;i--){
        heapify(a,i,n);
    }
    while(n>0){
    swap(&a->arr[0],&a->arr[n-1]);
    n=n-1;
    heapify(a,0,n);
    }
}
int is_reara(int *a,int *b,int n){
    for (int i=0;i<n;i++){
        if (a[i]==b[i])
        {
            return 0;
        }
    }
    return 1;
}
int count(int *a,int *b,int n){
    int count=0;
    for (int i=0;i<n;i++){
        if (a[i]==b[i]){
            count++;
        }
    }
    return  count;
}
void permutation(heap *a,int *b,int n,int start){
 for (int i=0;i<n-1;i++){
    if (a->arr[i]==b[i]){
        swap(&a->arr[i],&a->arr[i+1]);
    }
 }
  if (a->arr[n-1]==b[n-1]){
    swap(&a->arr[n-1],&a->arr[n-2]);
 }
 for (int i=0;i<n;i++){
    printf("%d ",a->arr[i]);
 }printf("\n");
 return ;
   
}