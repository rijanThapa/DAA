#include <stdio.h>
#include <limits.h>

#define INFINITY INT_MAX
#define MAX 10

void dijkstra(int costAdjMat[MAX][MAX], int vertices, int startNode);

int main()
{
    int vertices, startNode, costAdjMat[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the cost adjacency matrix with entry 0 for nonadjacent:\n");
    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            scanf("%d", &costAdjMat[i][j]);
        }
    }

    printf("Enter the starting node: ");
    scanf("%d", &startNode);

    dijkstra(costAdjMat, vertices, startNode);

    return 0;
}

void dijkstra(int costAdjMat[MAX][MAX], int vertices, int startNode)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX], visited[MAX];
    int count, minDistance, nextNode;

    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            if (costAdjMat[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = costAdjMat[i][j];
        }
    }

    for (int i = 1; i <= vertices; i++)
    {
        distance[i] = cost[startNode][i];
        pred[i] = startNode;
        visited[i] = 0;
    }
    distance[startNode] = 0;
    visited[startNode] = 1;
    count = 1;

    while (count < vertices - 1)
    {
        minDistance = INFINITY;
        for (int i = 1; i <= vertices; i++)
        {
            if (distance[i] < minDistance && !visited[i])
            {
                minDistance = distance[i];
                nextNode = i;
            }
        }
        visited[nextNode] = 1;
        for (int i = 1; i <= vertices; i++)
        {
            if (!visited[i])
            {
                if (minDistance + cost[nextNode][i] < distance[i])
                {
                    distance[i] = minDistance + cost[nextNode][i];
                    pred[i] = nextNode;
                }
            }
        }
        count++;
    }

    for (int i = 1; i <= vertices; i++)
    {
        if (i != startNode)
        {
            printf("\nDistance of node %d = %d\n", i, distance[i]);
            printf("Path = %d", i);
            int j = i;
            do
            {
                j = pred[j];
                printf("<-%d", j);
            } while (j != startNode);
            printf("\n");
        }
    }
}

