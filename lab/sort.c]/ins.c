#include <stdio.h>
#include <stdlib.h>
void ins_sor(int *a,int n){
    for (int i=0;i<n;i++){
        int temp=a[i];
        int index=i-1;
        while(index>=0&&a[index]>temp){
            a[index+1]=a[index];
            index--;
        }
        a[index+1]=temp;
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
    ins_sor(a,n);
}