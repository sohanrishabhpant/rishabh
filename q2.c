#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct tree{
    int data;
    struct tree*left;
    struct tree*right;
    int height;
}tree;
int max(int a,int b){
    return a>b?a:b;
}
int height(struct tree *t){
    if (t==NULL){
        return 0;
    }
    else{
        return t->height;
    }
}
tree*left_rotation(tree*root){
    tree*x=root->left;
    tree*flag=x->right;
    tree*y=root;
    y->left=flag;
    x->right=y;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}
tree*right_rotation(tree*root){
     tree*x=root->right;
    tree*flag=x->left;
    tree*y=root;
    y->right=flag;
    x->left=y;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}
tree*double_left_rotation(tree*root){
    tree*x=root->left;
    tree*x2=right_rotation(x);
    root->left=x2;
    x2=left_rotation(root);
    return x2;
}
tree*double_right_rotation(tree*root){
    tree*x=root->right;
    tree*y=x->left;
    root->right=left_rotation(x);
    root=right_rotation(root);
    return root;
}
tree*insert(tree*root,int data){
    tree*temp=malloc(sizeof (tree));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=data;
    temp->height=0;
    if (root==NULL){
        root=temp;
        return root;
    }
    else{
        if (root->data>data){
            root->left=insert(root->left,data);
            int balance=height(root->left)-height(root->right);
            if (balance==2){
                if (data<root->left->data){
                root=left_rotation(root);
            }
            else{
                root=double_left_rotation(root);
            }
            }
        }
        else if (root->data<data){
            root->right=insert(root->right,data);
            int balance=height(root->left)-height(root->right);
            if (balance==-2){
                if (data>root->right->data){
                    root=right_rotation(root);
                }
                else{
                    root=double_right_rotation(root);
                }
            }
        }
        
        return root;
    }
}
void inorder(tree*root){
  printf("root:%d",root->data);
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    tree*root=NULL;
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        root=insert(root,a[i]);
    }
    inorder(root);

}