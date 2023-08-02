#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node{
    int data;
    struct node*next;
    struct node *prev;
}node;
node *makenode (int data){
    node *temp=malloc(sizeof (node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
node *insert(node *head,int data){
    node *flag=head;
    while(flag->next!=NULL){
        flag=flag->next;
    }
    node *temp=makenode(data);
    flag->next=temp;
    temp->prev=flag;
    return head;
}
node *insert_at_curr(node *curr,int data,node*head){
    node *temp=makenode(data);
    temp->next=curr;
    node*previous=curr->prev;
    curr->prev=temp;
    previous->next=temp;
    temp->prev=previous;
    return head;
}
void print(node*head){
    node*flag=head;
  do{
    printf("%d ",head->data);
    head=head->next;
  }while(head!=NULL);
  printf("\n");
  while(flag->next!=NULL){
    flag=flag->next;
  }
  while(flag!=NULL){
    printf("%d ",flag->data);
    flag=flag->prev;
  }printf("\n");
}
int main(){
    node *head=makenode(1);
    head=insert(head,2);
    head=insert(head,3);
    node*curr=head->next;
    head=insert_at_curr(curr,4,head);
    head=insert(head,5);
    print(head);
}