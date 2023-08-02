#include <stdio.h>
#include <stdlib.h>

int size;

typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
} tree;
tree *makenode(int val)
{
    tree *temp = malloc(sizeof(tree));
    temp->data = val;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
int j = 0;

int max_index(long long int elem, long long int *ino, int start, int end)
{
    int* array = (int*) malloc(sizeof(int) * 1000000000);
    for (int i = start; i <= end; i++)
    {
        array[ino[i]] = i;
    }
    int index = array[elem];
    free(array);
    
    return index;
}
tree *construct_tree(long long int *pre, long long int *ino, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    static int k=0;
     tree *root = makenode(pre[k++]);
   
    
    int temp = pre[k-1];
  
    int index = max_index(temp, ino, start, end);
    

    root->left = construct_tree(pre, ino, start, index - 1);
   
    root->right = construct_tree(pre, ino, index + 1, end);
    return root;
}
int height(tree *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int rheight = 1 + height(head->right);
    int lheight = 1 + height(head->left);
    if (rheight > lheight)
    {
        return rheight;
    }
    else
    {
        return lheight;
    }
}
void print_at_given_level(tree *head, int i, int depth)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        if (depth == i)
        {
            printf("%d ", head->data);
            return;
        }
        else
        {
            print_at_given_level(head->left, i, depth + 1);
            print_at_given_level(head->right, i, depth + 1);
        }
    }
}
void print(tree *head)
{
    int h = height(head);
    for (int i = 1; i <= h; i++)
    {
        print_at_given_level(head, i, 1);
    }
}
void free_tree(tree *head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        free_tree(head->left);
        free_tree(head->right);
        free(head);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        j = 0;
        scanf("%d", &size);
        long long int pre[size];
        long long  int ino[size];
        for (int j = 0; j < size; j++)
        {
            scanf("%lld", &ino[j]);
        }
        for (int j = 0; j < size; j++)
        {
            scanf("%lld", &pre[j]);
        }
        tree *head = construct_tree(pre, ino, 0, size - 1);
        print(head);
        printf("\n");
        free_tree(head);
    }
}