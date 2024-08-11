#include <stdio.h>
#include <limits.h>

#define MAX 10
#define INF 999

int a, b, u, v, n, i, j, ne = 1;
int visited[MAX] = {0};
int mincost = 0;
int cost[MAX][MAX];

int find(int i)
{
    while (visited[i])
        i = visited[i];
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        visited[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("\n");

    while (ne < n)
    {
        int min = INF;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            printf("Edge %d: (%d %d) cost: %d\n", ne, a, b, min);
            ne++;
            mincost += min;
        }
        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}

