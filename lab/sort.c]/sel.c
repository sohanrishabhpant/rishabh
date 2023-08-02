#include<stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sel_sort(int *a,int n){
    int min;
    int index;
    for (int i=0;i<n-1;i++){
        min=a[i+1];
        for (int j=i+1;j<n;j++){
            if (min>=a[j]){
                min=a[j];
                index=j;
            }
        }
        if(min<a[i]){
            swap(&a[i],&a[index]);
        }
    }
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sel_sort(a,n);
}