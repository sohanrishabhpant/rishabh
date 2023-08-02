#include"functions.h"
void init(row_node *head,int row){
    row_node*temp=malloc(sizeof(row_node));
    temp->row=row;
    temp->down=NULL;
    temp->next=NULL;
    if (head->down==NULL){
        head->down=temp;
        return ;
    }
    else{
        while(head->down!=NULL){
            head=head->down;
        }
        head->down=temp;
        return ;
    }
}
void append_at_apart_row(row_node*head,int col,int val){
    struct node* temp=malloc(sizeof (node));
    temp->col=col;
    temp->val=val;
    temp->next=NULL;
    struct node *flag=head->next;
    if (flag==NULL){
        head->next=temp;
        return ;
    }
    else{
        while(flag->next!=NULL){
            flag=flag->next;
        }flag->next=temp;
    }
    return ;
}void init(row_node *head,int row){
    row_node*temp=malloc(sizeof(row_node));
    temp->row=row;
    temp->down=NULL;
    temp->next=NULL;
    if (head->down==NULL){
        head->down=temp;
        return ;
    }
    else{
        while(head->down!=NULL){
            head=head->down;
        }
        head->down=temp;
        return ;
    }
}
void append_at_apart_row(row_node*head,int col,int val){
    struct node* temp=malloc(sizeof (node));
    temp->col=col;
    temp->val=val;
    temp->next=NULL;
    struct node *flag=head->next;
    if (flag==NULL){
        head->next=temp;
        return ;
    }
    else{
        while(flag->next!=NULL){
            flag=flag->next;
        }flag->next=temp;
    }
    return ;
}
void print(row_node *temp){
    struct node *flag;
    while(temp!=NULL){
        flag=temp->next;
        printf("%d",temp->row);
    while(flag!=NULL){
        printf("%d%d",flag->col,flag->val);
        flag=flag->next;
    }printf("\n");
    temp=temp->down;
}

    while(temp!=NULL){
        flag=temp->next;
        printf("%d",temp->row);
    while(flag!=NULL){
        printf("%d%d",flag->col,flag->val);
        flag=flag->next;
    }printf("\n");
    temp=temp->down;
}}
