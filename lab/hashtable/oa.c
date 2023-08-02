#include <stdio.h>
#include <stdlib.h>
typedef struct hashtable{
    int *arr;
    int cap;
}hashtable;
hashtable*create(int cap){
    hashtable*temp=malloc(sizeof (hashtable));
    temp->cap=cap;
        temp->arr=malloc(sizeof (int)*cap);
    for (int i=0;i<cap;i++){
        temp->arr[i]=0;
    }
    return temp;
}
int fun(int key,hashtable*ht){
    int index=key%ht->cap;
    
    return index;
}
hashtable*insert(hashtable*ht,int key){
    int  index=fun(key,ht);
    int i=0;
    while(ht->arr[index+((i*i)%ht->cap)]!=0){
        i++;
    }
    index=index+((i*i)%ht->cap);
    ht->arr[index]=key;
    return ht;
}
int find(hashtable*ht,int key){
    int index=fun(key,ht);
    int currpos=0;
    int i=0;
    while(i<ht->cap/2){
        if (ht->arr[index+currpos]==key){
            return index;
        }
        currpos+=2*i+1;
        currpos=currpos%ht->cap;
        i++;
    }
     index+=(currpos)%ht->cap;
    
    return index;
}

int main(){
    hashtable*ht=create(7);
    ht=insert(ht,2);
    ht=insert(ht,9);
    ht=insert(ht,16);
    ht=insert(ht,23);
    printf("%d",find(ht,23));
}
// similarly you can linearly do and for quadratic probing you have to do table size/2
