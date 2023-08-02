#include "sort.c"
int main()
{
    int t;
    scanf("%d", &t);
    int k, m;
    int j;
    for (int i = 0; i < t; i++)
    {
        scanf("%d%d", &k, &m);
        int a[(k * m)];
        for (int i = 0; i < (k * m); i++)
        {
            scanf("%d", &a[i]);
        }
        scanf("%d", &j);
        int c[m];
        for (int i = 0; i <= (m - 1); i++)
        {
            c[i] = a[(k * i) + j - 1];
        }
        heap_sort(c, m);
        // for (int i=0;i<m;i++){
        //     printf("%d ",c[i]);
        // }printf("\n");
        for (int i = 0; i < m; i++)
        {
            a[(k * i) + j - 1] = c[i];
        }
        int d[m][k];
        int y;
        int max1[m];
        for (int i = 0; i < m; i++)
        {
            max1[i] = 0;
        }
        int max2;
        for (int i = 0; i < m; i++)
        {
            y=0;
            max2 = 0;
            for (int z = 0; z < k; z++)
            {
                if (z == j - 1)
                {
                    continue;
                }
                else
                {
                    d[i][y] = a[(k * i) + z];
                    max2 = max3(d[i][y], max2);
                    y++;
                }
            }
            max1[i] = max2;
        }
        int ans_count = 0;
        int z = 0;

        heap_sort(max1, m);
        // for (int i = 0; i < m;i++)
        // {
        //    printf("%d ",max1[i]);
        // }
        for (int i = 0; i < m;i++)
        {
            if (c[i] >= max1[z])
            {
                ans_count++;
                z++;
            }
        }
        printf("%d\n", ans_count);
    }
    return 0;
}
