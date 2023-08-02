#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int node;
    struct tree*left;
    struct tree*right;
}tree;

tree *addnode(int val){
    tree*temp=malloc(sizeof (tree));
    temp->node=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
tree*insert(tree*root,int val){
   tree*temp=addnode(val);
    if (root==NULL){
        return temp;
    }
    else{
        if (val<root->node)
        root->left=insert(root->left,val);
        else{
            root->right=insert(root->right,val);
        }
    }
    return root;
}
void preorder(tree *root){
    if (root==NULL){
        return ;
    }
    else{
    printf("%d",root->node);
    preorder(root->left);
    preorder(root->right);
}}
void preorder1(tree*root){
    // in iterative way
      tree*temp[1000];
        int top=0;
    if (root==NULL){
        return;
    }
    else{
      
        temp[top++]=root;
        while(top!=0){
            root=temp[--top];
            printf("%d",root->node);
             if (root->right!=NULL){
                temp[top++]=root->right;
            }
            if (root->left!=NULL){
                temp[top++]=root->left;
            }
        }

    }

}
void postorder(tree*root){
    if (root==NULL){
        return;
    }
    else{
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->node);
    }
}
tree *mirror(tree*head){
    tree *head1=NULL;
    if (head==NULL){
        return NULL;
    }
    
    else{
        head1=addnode(head->node);
        head1->right=mirror(head->left);
        head1->left=mirror(head->right);
    }
    return head1;
}
int main(){
    struct tree*temp=NULL;
    

 
    // struct tree*temp1=NULL;
    // temp1=mirror(temp);
     preorder1(temp);
    // preorder(temp1);


}

