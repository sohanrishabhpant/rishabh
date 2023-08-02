#ifndef FUNCTIONS_H
#define FUCNTIONS_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack{
    int top;
    char *arr;
}stack;
struct stack* init();
int matchingpair(char ch1,char ch2);
int isEmpty(stack*s);
int isFull(stack*s);
void push(stack *s,char val);
void pop(stack*s);
char top(const stack*s);
int balanced(char *s);
int  palindrome(char*s,int n);
int len(char *temp);
#endif