#include <stdio.h>
#include <stdlib.h>

typedef struct heap{
    int *arr;
    int size;
    int cap;
}heap;
heap* create(int cap);
void swap(int *a, int *b);
void heapify(heap *root, int i, int n);
void heap_insert(heap*root, int val);
int extract_min(heap *root);
int heap_count(int *a,int n);