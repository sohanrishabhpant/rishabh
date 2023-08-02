#include<stdio.h>
#include<stdlib.h>

 int j=1;
typedef struct tree{
    int data;
    struct tree*right;
    struct tree*left;
}tree;
tree*makenode(int val){
    tree*temp=malloc(sizeof (tree));
    temp->data=val;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}
tree* insert(tree*head,int val){
    
    if(head==NULL){
        tree*temp=makenode(val);
        return temp;
    } 
    else{
        if (head->data>val){
            head->left=insert(head->left,val);
        }
        else{
            head->right=insert(head->right,val);
        }
    }
    return head;
}
int height(tree*head){
    if (head==NULL){
        return 0;
    }
    int ldepth=1+height(head->left);
    int rdepth=1+height(head->right);
    if (ldepth>rdepth){
        return ldepth;
    }
    else{
        return rdepth;
    }
}
void print_at_level(tree*head,int depth,int lev){
if(head==NULL){
    return;
}
else{
    if(lev==depth){
        printf("%d ",head->data);
        return;
    }
    else{
        tree*flag=head;
        print_at_level(flag->left,depth,lev+1);
        print_at_level(flag->right,depth,lev+1);
    }
}
}
void print_at_rev(tree*head,int depth,int lev){
     if (head==NULL){
        return;
    }
     if (lev==depth){
            printf("%d ",head->data);
            return;
        }
   
        else{
            tree*flag=head;
            print_at_rev(head->right,depth,lev+1);
            print_at_rev(head->left,depth,lev+1);
        }
    }
   

void print_beauty(tree*head){
    if (head==NULL){
        return;
    }
    else{
        int h=height(head);
        printf("%d ",head->data);
        for (int i=2;i<=h;i++){
                if (i%2==0){
                     print_at_rev(head,i,1);
                }
                else{
                    print_at_level(head,i,1);
                }
            }
            }
        }
void free_tree(tree*head){
    if (head==NULL){
        return;
    }
    else{
        free_tree(head->left);
        free_tree(head->right);
        free(head);
       } 
    }

int main(){
    tree* head=NULL;
    int n;
    int flag=1;
    scanf("%d",&n);
    long long int num;
    for (int i=0;i<n;i++){
        scanf("%lld",&num);
        int *a=malloc(sizeof(int)*num);
        
        for (int j=0;j<num;j++){
            scanf("%d",&a[j]);
            head=insert(head,a[j]);
        }
        printf("%d",flag);
        if (flag==1){
        print_beauty(head);
        printf("\n");
        free_tree(head);
    }
}  }