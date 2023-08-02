#include"functions.c"
int main()
{   int m,n;
    int x;
    scanf("%d %d %d",&m,&n,&x);
     int count=0;
    struct row_node*head=malloc(sizeof (row_node));
    head->row=-1;
    head->down=NULL;
    head->next=NULL;
    int col,row,val;
    struct row_node*temp=head->down;
    for (int i=0;i<x;i++){
        scanf("%d %d %d",&row,&col,&val);
        init(head,row);
    }
     while(temp!=NULL){
        count++;
        temp=temp->down;
    }    
    print(head->down);
    printf("%d",count);
    row_node*flag=head;
   
}
