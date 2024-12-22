 #include <stdio.h>
#include <stdlib.h>
#define MAX 10

int cost[MAX][MAX];
int n;

void main()
{
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix (999 for infinity):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    prim();
}

void prim()
{
    int a, b, u, v, i, j, e;
    int visited[MAX] = {0}, min, mincost = 0;
    visited[0] = 1;

    printf("\nMinimum Spanning Tree Edges:\n");

    for (e = 0; e < n - 1; e++)
    {
        min = 999;
        for (i = 0; i < n; i++)
        {
            if (visited[i] != 0)
            {
                for (j = 0; j < n; j++)
                {
                    if (cost[i][j] < min && visited[j] == 0)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        visited[v] = 1;
        printf("Edge %d: (%d, %d) cost: %d\n", e + 1, a + 1, b + 1, min);
        mincost += min;
    }

    printf("\nMinimum cost = %d\n", mincost);
}
