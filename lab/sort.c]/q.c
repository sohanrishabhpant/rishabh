#include<stdio.h>
#include <stdlib.h>


void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int quick(int *a,int l,int r){
    int pivot=a[r];
    int i=l-1;
    for (int j=l;j<=r-1;j++){
        if (a[j]<pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[r]);
    return i+1;
}
void quick_sort(int *a,int l,int r){
    if (l<r){
    
    int partition=quick(a,l,r);
    quick_sort(a,l,partition-1);
    quick_sort(a,partition+1,r);
}}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    quick_sort(a,0,n-1);
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}