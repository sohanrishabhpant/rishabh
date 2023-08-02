#include"sort.c"
int main(){
    int t;
    int n,k;
    scanf("%d",&t);
    for (int i=0;i<t;i++){
    scanf("%d %d",&n,&k);
   long long  int sum=0;
    int a[n];
    int b[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    heap(b,n);
    heap_sort(a,n);
    sum+=a[n-1];
    a[n-1]=a[n-1]-1;
    b[0]=a[n-1];
    heapify(b,0,n);
    for (int i=1;i<k;i++){
        int root=max(b,n);
        if (root>0){
        sum+=root;
        root--;
        b[0]=root;
        heapify(b,0,n);
    }}
    printf("%lld\n",sum);
}}
