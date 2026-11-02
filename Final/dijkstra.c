#include <stdio.h>
#define INF 9999
int main()
{
 int n, cost[10][10], dist[10], visited[10];
 int i, j, count, u, source, min;
 printf("Enter number of vertices: ");
 scanf("%d", &n);
 printf("Enter cost matrix:\n");
 for (i = 0; i < n; i++)
 for (j = 0; j < n; j++)
 scanf("%d", &cost[i][j]);
 printf("Enter source vertex: ");
 scanf("%d", &source);
 for (i = 0; i < n; i++)
 {
 dist[i] = INF;
 visited[i] = 0;
 }
 dist[source] = 0;
 for (count = 1; count < n; count++)
 {
 min = INF;
 u = -1;
 for (i = 0; i < n; i++)
 {
 if (!visited[i] && dist[i] < min)
 {
 min = dist[i];
 u = i;
 }
 }
 if (u == -1)
 break;
 visited[u] = 1;
 for (j = 0; j < n; j++)
 {
 if (!visited[j] && cost[u][j] != 0 &&
 dist[u] + cost[u][j] < dist[j])
 {
 dist[j] = dist[u] + cost[u][j];
 }
 }
 }
 printf("\nShortest distances from source %d:\n", source);
 for (i = 0; i < n; i++)
 {
 if (dist[i] == INF)
 printf("Vertex %d: Unreachable\n", i);
 else
 printf("Vertex %d: %d\n", i, dist[i]);
 }
 return 0;
}
