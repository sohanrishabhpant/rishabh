#include "hash.c"
int main(){
    int n,q;
   hashtable*ht=create(100000);
   scanf("%d %d",&n,&q);
   char a[n][11];
   char b[q][11];
   for (int i=0;i<n;i++){
    scanf("%s",a[i]);
    ht=insert(ht,a[i]);
   }
   for (int i=0;i<q;i++){
    scanf("%s",b[i]);
     print(ht,b[i]);}
   }
   