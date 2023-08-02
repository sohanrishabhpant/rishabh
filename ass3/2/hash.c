#include "hash.h"
int is_palindrome(char *a,int l,int r){
    for (int i=l;i<r;i++){
        if (a[i-1]!=a[r-1]){
            return 0;
        }
        r--;
    }
    return 1;
}