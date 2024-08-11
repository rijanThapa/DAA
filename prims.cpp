#include <stdio.h>
#include <limits.h>  // For INT_MAX

#define MAX 10

int a, b, u, v, n, i, j, ne = 1;
int visited[MAX] = {0};
int mincost = 0;
int cost[MAX][MAX];

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
                cost[i][j] = INT_MAX;  // Use INT_MAX to represent infinity
        }
    }

    visited[1] = 1;
    printf("\n");
    
    while (ne < n)
    {
        int min = INT_MAX;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    if (visited[i] != 0)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        
        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("Edge %d: (%d %d) cost: %d\n", ne, a, b, min);
            ne++;
            mincost += min;
            visited[b] = 1;
        }
        
        cost[a][b] = cost[b][a] = INT_MAX; 
		}
    
    printf("Minimum cost = %d\n", mincost);

    return 0;
}

