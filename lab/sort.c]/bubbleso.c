#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bublesort(int *a,int n){
    int flag;
    for (int i=0;i<n;i++){
        flag=0;
        for (int j=0;j<n-i-1;j++){
            if (a[j]>a[j+1]){
                flag=1;
                swap(&a[j],&a[j+1]);
            }
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
    bublesort(a,n);
}