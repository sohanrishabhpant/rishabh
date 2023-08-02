#include "hash.c"
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    char*a=malloc(sizeof (char)*n);
    scanf("%s",a);
    int l[q],r[q];
    for (int i=0;i<q;i++){
        scanf("%d %d",&l[i],&r[i]);
    }
    for (int i=0;i<q;i++){
    if (is_palindrome(a,l[i],r[i])){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    }
}