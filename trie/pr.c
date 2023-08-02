#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct trie{
    struct trie *arr[26];
    bool flag;
}trie;
trie*create(){
    trie*temp=malloc(sizeof(trie));
    for (int i=0;i<26;i++){
        temp->arr[i]=NULL;
    }
    temp->flag=0;
    return temp;
}
void insert(trie*root,char *str){
    int len=strlen(str);
    for (int i=0;i<len;i++){
        int index=
    }
}