#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
typedef struct hashtable{
    node**arr;
    int capacity;
}hashtable;
hashtable* create(int capacity){
hashtable *temp=malloc(sizeof(hashtable));
temp->capacity=capacity;
temp->arr=malloc(sizeof (node*)*capacity);
for (int i=0;i<capacity;i++){
    temp->arr[i]=malloc(sizeof (node));
    temp->arr[i]->next=NULL;
}
return temp;
}
int gethash(hashtable*ht,int key){
    int index=key%ht->capacity;
    return index;
}
node *makenode(int data){
    node *temp=malloc(sizeof (node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
hashtable *insert(hashtable*ht,int key){
    int index=gethash(ht,key);
    node*temp=ht->arr[index]->next;
    node *flag=makenode(key);
    if (temp==NULL){
       ht->arr[index]->next=flag;
    }
    else{
        flag->next=ht->arr[index]->next;
        ht->arr[index]->next=flag;
    }
    return ht;
}
node *find(hashtable*ht,int key){
    int index=gethash(ht,key);
    node *temp=ht->arr[index]->next;
    node *flag=NULL;
    while(temp!=NULL&&key!=temp->data){
            temp=temp->next;
        
    }
    if (key==temp->data){
        flag=temp;
    }
    return flag;
}

int main(){
    hashtable *ht=create(100000);
    ht=insert(ht,22);
    ht=insert(ht,9);
    node*temp=find(ht,9);
    if (temp==NULL){
        printf("%d",0);
    }
    else{
        printf("%d",1);
    }
}