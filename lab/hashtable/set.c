#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
typedef struct set{
    int size;
    node**arr;
}set;
set*create(){
    set*temp=malloc(sizeof (set));
    temp->arr=(node*)malloc(sizeof(node*)*10000);
    for (int i=0;i<10000;i++){
        temp->arr[i]=malloc(sizeof (node));
        temp->arr[i]->next=NULL;
    }
    temp->size=0;
    return temp;
}
void insert(set*s,int key){
    int index=gethash(s,key);
   if (s==NULL){
    s->arr[index]=makenode(key)
   }
}
int main(){

}