#include"functions.c"
int main()
{
    Queue head = create();
    int n;
    scanf("%d", &n);
    int val;
    int val1;
    int k;
    int pos;
    int val2;
    for (int i = 0; i < n; i++)
    {
        char arr[1000];
        scanf("%s", arr);
        char ch = arr[4];
        switch (ch)
        {
        case '1':
            scanf("%d", &val);
            Push(head, val);
            break;
        case '2':
            printf("%d\n", Pop(head));
            break;
        case '3':
            scanf("%d", &val1);
            Inject(head, val1);
            break;
        case '4':
            val2 = popRear(head);
            printf("%d\n", val2);
            break;
        case '5':
            Print(head);
            printf("\n");
            break;
        case '6':
            PrintReverse(head);
            count = 0;
            printf("\n");
            break;
        case '7':
            scanf("%d", &pos);
            printf("%d\n", findElem(head, pos));
            break;
        case '8':
            scanf("%d", &k);
            remKElemes(head, k);
            break;
        }
    }
    return 0;
}
