#include<stdio.h>
#include <stdlib.h>
typedef struct heap{
    int *arr;
    int cap;
    int size;
}heap;
void swap(int *a,int *b);
heap* create(int cap);
void heapify(heap *a,int i,int n);
void heap_insert(heap*root, int val);
void heap_sort(heap *a,int n);
int is_reara(int *a,int *b,int n);
int count(int *a,int *b,int n);
void permutation(heap *a,int *b,int n,int start);