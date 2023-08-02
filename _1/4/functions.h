#include<stdio.h>
#include<stdlib.h>
typedef struct row_node{
    int row;
    struct node*next;
    struct row_node*down;
}row_node;
struct node{
    int col;
    int val;
    struct node*next;
}node;
void init(row_node *head,int row);
void append_at_apart_row(row_node*head,int col,int val);
void init(row_node *head,int row);