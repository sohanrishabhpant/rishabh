#include <stdio.h>
#include <stdlib.h>


void merg(int *a,int l,int mid,int u){
    int left=mid-l+1;
    int right=u-mid;
    int le[left],ri[right];
    for (int i=0;i<=mid-l;i++){
        le[i]=a[i+l];
    }
    for (int i=0;i<=u-mid-1;i++){
        ri[i]=a[i+mid+1];
    }
    int k1=0;
    int k2=0;
    int r=l;
    while(k1<left&&k2<right){
        if (le[k1]>ri[k2]){
            a[r]=ri[k2];
            k2++;
            r++;
        }
        if (le[k1]<ri[k2]){
            a[r]=le[k1];
            k1++;
            r++;
        }
    }
    while(k1<left){
        a[r]=le[k1];
        k1++;
        r++;
    }
    while(k2<right){
        a[r]=ri[k2];
        k2++;
        r++;
    }
}
void merg_sort(int *a,int l,int u){
    if (l<u){
        int mid=(l+u)/2;
        merg_sort(a,l,mid);
        merg_sort(a,mid+1,u);
        merg(a,l,mid,u);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    merg_sort(a,0,n-1);
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}