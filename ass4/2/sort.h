#ifndef __SORTS_H_
#define __SORTS_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    int a;
    int b;
}point;
int left_child(int i);
int right_child(int i);
void swap(point *a,point *b);
void heapify(point *c,int i,int n);
void heap_sort(point *c,int n);
#endif
