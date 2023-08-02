#include"sort.h"
int left_child(int i){
    return 2*i+1;
}
int right_child(int i){
    return 2*i+2;
}
void swap(point *a,point *b){
    point temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(point *c,int i,int n){
    int left=left_child(i);
    int right=right_child(i);
    int largest=i;
    if (left<n&&c[largest].a<c[left].a){
        // if (c[largest].b<c[left].b&&c[largest].a==c[left].a){
        //     largest=left;
        // }}
        largest=left;
    }
    if (right<n&&c[largest].a<c[right].a){
        // if (c[largest].b<c[right].b&&c[largest].a==c[right].a){
        //     largest=right;
        // }}
        largest=right;
    }
    if (left<n&&c[largest].a==c[left].a){
        if (c[largest].b<c[left].b){
            largest=left;
        }
    }
    if (right<n&&c[largest].a==c[right].a){
        if (c[largest].b<c[right].b){
            largest=right;
        }
    }
    if (largest!=i){
        swap(&c[largest],&c[i]);
        heapify(c,largest,n);
    }
}
void heap_sort(point *c,int n){
    for (int i=(n-1)/2;i>=0;i--){
        heapify(c,i,n);
    }
    while(n>0){
        swap(&c[0],&c[n-1]);
        n=n-1;
        heapify(c,0,n);
    }
}