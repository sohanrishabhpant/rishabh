#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
    int data;
    struct tree*left;
    struct tree*right;
}tree;
tree*makenode(int val){
    tree*temp=malloc(sizeof (tree));
    temp->left=NULL;
    temp->data=val;
    temp->right=NULL;
    return temp;
}
tree*makebinatree(tree*root,int val,int n){
    tree*temp=makenode(val);
    static int count=0;
    if (root==NULL){
        return temp;
    }
    
    else{
        count++;
        if (count%2==1){
        root->left=makebinatree(root->left,val,n);
        
    }
    else{
        root->right=makebinatree(root->right,val,n);
    }
    }
    return root;
}
void preorder (tree*root){
    if (root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
int main(){
    tree*head=NULL;
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
         head=makebinatree(head,a[i],n);
    }
    preorder(head);
   
}