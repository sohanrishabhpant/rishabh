#include "sort.h"

void swap(char **a,char **b){
    char *string=*a;
    *a=*b;
   *b=string;
}
int left_child(int i){
    return 2*i+1;
}
int right_child(int i){
    return 2*i+2;
}
int len(char *a){
    int count=0;
    for (int i=0;a[i];i++){
        count++;
    }
    return count;
}
int min(int a,int b){
    return a>b?b:a;
}
int comparator(char *a,char *b){
    int min_len=min(len(a),len(b));
    int i;
    for ( i=0;i<min_len;i++){
        if (a[i]!=b[i]&&i%2==0){
            if (a[i]>b[i]){
                return 1;
            }
            else{
                return 0;
            }
            break;
        }
          if (a[i]!=b[i]&&i%2==1){
            if (a[i]<b[i]){
                return 1;
            }
            else{
                return 0;
            }
            break;
        }
    }
    if (i==min_len&&len(a)<len(b)){
        if (len(a)%2==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if (i==min_len &&len(a)>len(b)){
        if (len(b)%2==1){
            return 1;
        }
        else{
            return 0;
        }
    }
}
void heapify(char **a,int i,int n){
int left=left_child(i);
int right=right_child(i);
int largest=i;
if (left<n&&comparator(a[left],a[largest])){
    largest=left;
}
if (right<n&&comparator(a[right],a[largest])){
    largest=right;
}
if (largest!=i){
    swap(&a[largest],&a[i]);
    heapify(a,largest,n);
}
}
void heapsort(char **a,int n){
    for (int i=(n-1)/2;i>=0;i--){
        heapify(a,i,n);
    }
    while(n>0){
        swap(&a[0],&a[n-1]);
        n=n-1;
        heapify(a,0,n);
    }
}
