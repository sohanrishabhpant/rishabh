#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
    return a>b?a:b;
}
int max_function(int *a,int n,int k,int i){
    int arr[1000000];
    int j=i;
    int top=-1;
    int max1=0;
    while(k-1){
        arr[++top]=a[j];
        k--;
        j++;
    }
    max1=arr[top--];
    while(top!=-1){
        max1=max(arr[top--],max1);
    }
    return max1;
}
int main(){
    int t;
    scanf("%d",&t);
    int  n,k;
    int max1;
    for (int i=0;i<t;i++){
        
    scanf("%d %d",&n,&k);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n;i++){
       int temp=max_function(a,n,k,i);
       printf("%d ",temp);
    }
    printf("\n");
    }
}