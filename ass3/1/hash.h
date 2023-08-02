#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    char *arr1;
    struct node *next;
}node;
typedef struct hashtable{
    node **arr;
    int capacity;
}hashtable;

hashtable*create(int capacity);
node *makenode (char*arr);
int size(char *arr);
int cub(int a);
int get_key(hashtable*ht,char*arr);
hashtable*insert(hashtable *ht,char *arr1);
int is_anagram(char*temp1,char*temp2);
void print(hashtable*ht,char *arr1);