#ifndef __SORT_H_
#define __SORT_H_
#include <stdio.h>
#include <stdlib.h>

void swap(char **a,char **b);
int left_child(int i);
int right_child(int i);
int len(char *a);
int min(int a,int b);
int comparator(char *a,char *b);
void heapify(char **a,int i,int n);
void heapsort(char **a,int n);
#endif