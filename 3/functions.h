#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node* PtrNode;
typedef struct node{
    int Element;
    PtrNode NextNode;
}node;
void Print(PtrNode Head);
void Insert (PtrNode Head,int num);
PtrNode Find(PtrNode Head,int num);
