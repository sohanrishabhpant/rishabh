#include <stdio.h>
#include <stdlib.h>


void shell_sort(int *a,int n){
    for (int gap=n/2;gap>=1;gap/=2){
        for (int i=gap;i<n;i++){
            int temp=a[i];
            int j;
            for (j=i;j>=gap&&a[j-gap]>temp;j-=gap){
                a[j]=a[j-gap];
            }
            a[j]=temp;
        }
        printf("\n");
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    shell_sort(a,n);
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}