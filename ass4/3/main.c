#include"sort.c"

int main(){
    int t;
    scanf("%d",&t);
    int n;
    for (int i=0;i<t;i++){
        scanf("%d",&n);
         int len1[n];
        char *a[n];
        for (int i=0;i<n;i++){
            scanf("%d",&len1[i]);
            a[i]=malloc(sizeof (char)*(len1[i]+1));
           scanf("%s",a[i]);
        }
        heapsort(a,n);
        for (int i=0;i<n;i++){
            printf("%s\n",a[i]);
        }
    }
}