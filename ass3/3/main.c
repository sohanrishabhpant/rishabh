#include "heap.c"

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d\n",heap_count(a,n));
}
               

