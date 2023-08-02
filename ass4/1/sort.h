#ifndef __SORT_H_
#define __SORT_H_
#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b);
void heapify(int *a,int i,int n);
void heap_sort(int *a,int n);
#endif