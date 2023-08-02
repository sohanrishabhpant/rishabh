
#include "functions.c"
int main()
{
    PtrNode Head = malloc(sizeof(node));
    Head->Element = 0;
    Head->NextNode = Head;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char *a = malloc(sizeof(char) * 6);
        int num;

        scanf("%s", a);
        char ch = a[4];
        switch (ch)
        {
        case '1':
        {
            scanf("%d", &num);
            Insert(Head, num);
            break;
        }
        case '2':
        {
            scanf("%d", &num);
            Find(Head, num);
            break;
        }
        case '3':
        {
            Print(Head);
            break;
        }
        }
    }
}