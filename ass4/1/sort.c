#include"sort.h"
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int *a,int i,int n){
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if (left<n&&a[i]<a[left]){
        largest=left;
    }
    if (right<n&&a[largest]<a[right]){
        largest=right;
    }
    if (largest!=i){
        swap(&a[i],&a[largest]);
        heapify(a,largest,n);
    }
}
void heap_sort(int *a,int n){
    for (int i=n-1/2;i>=0;i--){
        heapify(a,i,n);
    }
    while(n>0){
    swap(&a[0],&a[n-1]);
    n=n-1;
    heapify(a,0,n);}
}
void heap(int *b,int n){
    for (int i=n-1/2;i>=0;i--){
        heapify(b,i,n);
    }
}
int max(int *b,int n){
    return b[0];
}