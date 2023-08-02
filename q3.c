#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node*left;
    struct node *right;
}node;
node *makenode (int data){
    node *temp=malloc(sizeof (node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
node *insert(node *root,int data){
    node *temp=makenode (data);
    if (root==NULL){
        root=temp;
        return root;
    }
    else{
        if (root->data<data){
            root->right=insert(root->right,data);
        }
        else{
             root->left=insert(root->left,data);
        }
        return root;
    }
}
// void inorder(node *temp){
// if (temp==NULL){
//     return;
// }
// inorder(temp->left);
// printf("%d",temp->data);
// inorder(temp->right);
// }
node  *ans(node *temp,int *se,int i){
    node *flag=temp;
    if (temp==NULL){
        return NULL;
    }
        if (se[i]==temp->left->data){
           flag=flag->left;
        }
        if (se[i]==temp->right->data){
            flag=flag->right;
        }
        return flag;
    }
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    node *temp=NULL;
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        temp=insert(temp,a[i]);
    }
    int k;
    scanf("%d",&k);
    int *se=malloc(sizeof (int)*k);
    for(int i=0;i<n;i++){
        scanf("%d",&se[k]);
    }
    node *temp=ans(temp,se,1);
    printf("%d\n",temp->data);

    // inorder(temp);
}