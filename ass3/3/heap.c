#include "heap.h"

heap* create(int cap){
    heap* temp=malloc(sizeof (heap));
    temp->size=0;
    temp->cap=cap;
    temp->arr=malloc(sizeof (int)*cap);
    return temp;
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(heap *root, int i, int n) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && root->arr[left] <= root->arr[smallest]) {
        smallest = left;
    }

    if (right < n && root->arr[right] <= root->arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&(root->arr[i]), &(root->arr[smallest]));
        heapify(root, smallest, n);
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

int extract_min(heap *root) {
    if (root->size == 0) {
        return 0; 
    }

    int root1 = root->arr[0];
    root->arr[0] = root->arr[root->size - 1];
    (root->size)--;
    heapify(root, 0, root->size);
    return root1;
}
int heap_count(int *a,int n){
int index = 0;
    int ans_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            index = i;
            break;
        }
    }
    long long int sum = 0;
    long long int neg_count=0;
    for (int i=index;i<n;i++){
        if (a[i]<0){
            neg_count++;
        }
    }
    heap*b=create(1000000);
    int count=0;
    for (int i = index; i <n;)
    { 
        
        sum+=a[i];
        if (sum>=0&&a[i]>=0){
           
            ans_count++;
             i++;
        }
        else if (sum>=0&&a[i]<0){
            
            heap_insert(b,a[i]);
            ans_count++;
            i++;
        }
        else if (sum<0&&a[i]<0){
    int x=extract_min(b);
    if (a[i]<x){
        sum-=a[i];
        heap_insert(b,x);
    }
    else{
        sum-=x;
        heap_insert(b,a[i]);
    }
        i++;
    }
    }
    free(b);
     return ans_count;
    }
