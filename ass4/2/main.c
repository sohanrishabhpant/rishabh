

#include"sort.c"
int main(){
    int t;
    scanf("%d",&t);
    int n;
    for (int i=0;i<t;i++){
        scanf("%d",&n);
        int arr[n];
        int brr[n];
        point c[n];
        for (int i=0;i<n;i++){
            scanf("%d",&arr[i]);
            c[i].a=arr[i];
        }
        for (int i=0;i<n;i++){
            scanf("%d",&brr[i]);
            c[i].b=brr[i];
        }
        heap_sort(c,n);
        printf("%d ",c[n-1].a);
        for (int i=0;i<=n-1;i++){
            if (i==0&&c[0].a>c[0].b){
                c[0].a=c[0].b;
            }
            if (i==n-1&&c[n-1].a>=c[n-1].b&&c[n-1].b>=c[n-2].a){
                c[n-1].a=c[n-1].b;
            }
            else if (c[i].a>c[i].b&&c[i].b>=c[i-1].a&&c[i].b<=c[i+1].a){
                c[i].a=c[i].b;
            }
        }
        printf("%d",c[n-1].a);
        printf("\n");
            }
}