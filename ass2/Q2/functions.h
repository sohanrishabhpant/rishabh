#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
extern int count; 
typedef struct qnode
{
    int data;
    struct qnode *next;
} qnode;
typedef struct queue *Queue;
typedef struct queue
{
    qnode *front;
    qnode *rear;
} queue;
qnode *makenode(int val);
Queue create();
void Push(Queue head, int val);
int Pop(Queue head);
void Inject(Queue head, int val);
int popRear(Queue head);
void Print(Queue head);
void PrintReverse(Queue head);
int len(Queue head);
int findElem(Queue head, int pos);
void remKElemes(Queue head, int k);
#endif


