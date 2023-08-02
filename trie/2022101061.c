#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct trie{
    struct trie *arr[26];
    bool flag;
}trie;
typedef struct node{
    char *str;
    struct node*next;
}node;
typedef struct heap{
    node *arr;
    int size;
    int cap;
}heap;
heap*create_heap(int cap){
    heap*temp=malloc(sizeof (heap));
    temp->size=0;
    temp->cap=cap;
    temp->arr=malloc(sizeof(node)* cap);
    return temp;
}
void swap(node *a,node *b){
    node temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(heap*root,int i,int n){
    int smallest=i;
    int left_child=2*i+1;
    int right_child=2*i+2;
    if (left_child<n&&strcmp(root->arr[i].str,root->arr[left_child].str)<0){
        smallest=left_child;
    }
    if (right_child<n&&strcmp(root->arr[smallest].str,root->arr[right_child].str)<0){
        smallest=right_child;
    }
    if (smallest!=i){
        swap(&root->arr[smallest],&root->arr[i]);
        heapify(root,smallest,n);
    }
}
void heapsort(heap*root,int n){
    for (int i=n-1/2;i>=0;i--){
        heapify(root,i,n);
    }
    while(n>0){
    swap(&root->arr[0],&root->arr[n-1]);
    n--;
    heapify(root,0,n);
}}
trie *create(){
    trie*temp=malloc(sizeof (trie));
    temp->flag=false;
    for(int i=0;i<26;i++){
        temp->arr[i]=NULL;
    }
    return temp;
}
void insert(trie*root,char *str){
    int len=strlen(str);
    for (int i=0;i<len;i++){
        int index=str[i]-'a';
        if (root->arr[index]==NULL){
        root->arr[index]=create();
        root->flag=true;
        }
        root=root->arr[index];
    }
}
bool search(trie*root,char *str){
    int len=strlen(str);
    for (int i=0;i<len;i++){
        int index=str[i]-'a';
        if (root->arr[index]==NULL){
            return false;
        }
        root=root->arr[index];
    }
    return true;
}
void print(char **arr,int n){
    for (int i=0;i<n;i++){
        printf("%s\n",arr[i]);
    }
}
void print_arr(trie**root,char**arr,int s,int count,char**flag){
    int count1=0;
    char**ans=flag;
    int count2=0;
    int count3=0;
     for (int i=0;i<count;i++){
        heap*root1=create_heap(1000);
        count3=0;
        count2=0;
        // printf("%s\n",arr[i]);
        for (int j=0;j<s;j++){
            if (search(root[j],arr[i]))
            {
                count1++;
            }
        }printf("%d ",count1);
         for (int j=0;j<s;j++){
            if (search(root[j],arr[i]))
            {
                root1->arr[count2++].str=flag[j];
            }
        }
        heapsort(root1,count2);
        for (int j=0;j<s;j++){
            if (search(root[j],arr[i])){
                printf("%s ",root1->arr[count3++].str);
            }
        }
        count1=0;
        printf("\n");
     }
    }

int main(){
    int s;
    scanf("%d",&s);
    int n;
    trie**temp=malloc(sizeof (trie*)*s);
    char**flag=malloc(sizeof (char*)*s);
    for (int j=0;j<s;j++){
        flag[j]=malloc(sizeof (char)*1000);
    }
    int total=0;
    for (int i=0;i<s;i++){
        scanf("%d",&n);
        temp[i]=create();
        char **gue=malloc(sizeof (char*)*(n+1));
        for (int j=0;j<n+1;j++){
            gue[j]=malloc(sizeof(char)*1000);
        }
        for (int j=0;j<n+1;j++)
        {
            scanf("%s",gue[j]);
            if (j!=0){
            insert(temp[i],gue[j]);
            }
            if (j==0){
                flag[total++]=gue[0];
            }
        }
    }
        int count;
        scanf("%d",&count);
        char **arr=malloc(sizeof (char*)*count);
        for (int j=0;j<count;j++){
            arr[j]=malloc(sizeof (char)*1000);
        }
        for (int j=0;j<count;j++){
            scanf("%s",arr[j]);
        }
        print_arr(temp,arr,s,count,flag);
    
}
