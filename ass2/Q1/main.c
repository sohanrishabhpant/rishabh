#include"functions.c"
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
    char *temp=malloc(sizeof (char)*10000);
    scanf("%s",temp);
    int n=len(temp);
    if (palindrome(temp,n)&&balanced(temp)){
        printf("Balanced and Palindromic\n");
    } 
    else if (palindrome(temp,n)){
        printf("Palindromic\n");
    }
    else if (balanced(temp)){
        printf("Balanced\n");
    }
    else{
        printf("%d\n",-1);
    }
    free(temp);
}}