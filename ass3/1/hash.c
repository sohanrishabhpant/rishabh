#include "hash.h"
hashtable*create(int capacity){
    hashtable*temp=malloc(sizeof (hashtable));
    temp->capacity=capacity;
    temp->arr=(node**)malloc(sizeof (node*)*capacity);
    for (int i=0;i<capacity;i++){
        temp->arr[i]=malloc(sizeof (node));
        temp->arr[i]->next=NULL;
    }
    return temp;
}
node *makenode (char*arr){
    node *temp=malloc(sizeof (node));
    temp->arr1=arr;
    temp->next=NULL;
    return temp;
}
int size(char *arr){
    int count=0;
    for (int i=0;arr[i];i++){
        count++;
    }
    return count;
}
int cub(int a){
    return a*a;
}
int get_key(hashtable*ht,char*arr){
    int len=size(arr);
    int ha_val=0;
    for (int i=0;i<len;i++){
        ha_val+=cub(arr[i]-'a'+1);
        ha_val=ha_val%ht->capacity;
    }
    return ha_val;
}

hashtable*insert(hashtable *ht,char *arr1){
    int key=get_key(ht,arr1);
    node *flag=makenode (arr1);
    node *temp=ht->arr[key]->next;
    if (temp==NULL){
        ht->arr[key]->next=flag;
        return ht;
    }
    else{
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=flag;
    return ht;}
}
int is_anagram(char*temp1,char*temp2){
    int *arr=malloc(sizeof (int)*26);
    for (int i=0;i<26;i++){
        arr[i]=0;
    }
    for (int i=0;i<size(temp1);i++){
        arr[temp1[i]-'a']++;
    }
    for (int i=0;i<size(temp2);i++){
        if (arr[temp2[i]-'a']==0){
            return 0;
        }
        else{
            arr[temp2[i]-'a']--;
        }
    }
    return 1;
}
void print(hashtable*ht,char *arr1){
    int index=get_key(ht,arr1);
    node *temp=ht->arr[index]->next;
    if (temp==NULL){
        printf("%d\n",-1);
    }
    else{
        int count=0;
        while(temp!=NULL){
            if (is_anagram(temp->arr1,arr1)){
                count++;
            printf("%s ",temp->arr1);}
            temp=temp->next;
        }
        if (count==0)
        {
            printf("%d",-1);
        }
        printf("\n");
    }
}