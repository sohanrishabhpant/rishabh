#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
void add(node **head, int data)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    node *flag = *head;
    while ((flag)->next != NULL)
    {
        (flag) = (flag)->next;
    }
    (flag)->next = temp;
}
void insert(node **head, int data)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
    }
}
void print(node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }
}
node *merge(node *head1, node *head2)
{
    node *temp=head1;
    node *flag1 = head1;
    node *flag2 = head2;
    
    // printf("%d",temp->data);
    while (flag1 != NULL)
    {
       flag2=flag2->next;
        head2->next=head1->next;
        flag1=flag1->next;
        head1->next=head2;
         head1=flag1;
         head2=flag2;
    }
    return temp;
}

int main()
{
    node *head1 = NULL;
    insert(&head1, 1);
    add(&head1, 2);
    add(&head1, 3);
    // print(head1) ;      //output 1 2 3
    node *head2 = NULL;
    insert(&head2, 1);
    add(&head2, 2);
    add(&head2, 3);
    // print(head2);    //output 1 2 3
    node *flag = merge(head1, head2);
    print(flag);
}
