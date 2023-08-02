#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct stack{
    int capacity;
    int top;
    int *arr;
}stack;
int isop(char ch){
    if (ch=='+'){
        return 1;
    }
    if (ch=='-'){
        return 2;
    }
    if (ch=='/'){
        return 3;
    }
    if (ch=='*'){
        return 4;
    }
}
char * coin_prefix(char*s){
    char *temp=malloc(sizeof (char)*1000);
    int i=0;
    while(s[i]){
        if (!isop){
         temp[z++]=s[i];   
        }
        if (isop){
            if (stack s==NULL){
                push(&s,s[i]);
            }
            else{
                if (seek (s)<s[i]){
                    char ch=pop(&s);
                    temp[z++]=ch;
                }
            }
        }i++;

    }
}