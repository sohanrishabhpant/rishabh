#ifndef __SORT_H_
#define __SORT_H_
#include<stdio.h>
#include<stdlib.h>
int max3(int a, int b);
int left_child(int i);
int right_child(int i);
int comp(int a, int b);
void swap(int *a, int *b);
void heapify(int *a, int i, int n);
void heap_sort(int *a, int n);
#endif
