#include <stdio.h>
int graph[20][20], visited[20];
int stack[20], queue[20];
int n, top = -1, front = 0, rear = -1;
void DFS(int s)
{
 int i, v;
 for (i = 0; i < n; i++)
 visited[i] = 0;
 top = -1;
 stack[++top] = s;
 printf("DFS Traversal: ");
 while (top != -1)
 {
 v = stack[top--];
 if (!visited[v])
 {
 visited[v] = 1;
 printf("%d ", v);
 for (i = n - 1; i >= 0; i--)
 {
 if (graph[v][i] == 1 && !visited[i])
 stack[++top] = i;
 }
 }
 }
 printf("\n");
}
void BFS(int s)
{
 int i, v;
 for (i = 0; i < n; i++)
 visited[i] = 0;
 front = 0;
 rear = -1;
 queue[++rear] = s;
 visited[s] = 1;
 printf("BFS Traversal: ");
 while (front <= rear)
 {
 v = queue[front++];
 printf("%d ", v);
 for (i = 0; i < n; i++)
 {
 if (graph[v][i] == 1 && !visited[i])
 {
 visited[i] = 1;
 queue[++rear] = i;
 }
 }
 }
 printf("\n");
}
int main()
{
 int e, i, u, v, s;
 printf("Enter number of vertices: ");
 scanf("%d", &n);
 printf("Enter number of edges: ");
 scanf("%d", &e);
 for (i = 0; i < n; i++)
 for (int j = 0; j < n; j++)
 graph[i][j] = 0;
 printf("Enter edges (u v):\n");
 for (i = 0; i < e; i++)
 {
 scanf("%d%d", &u, &v);
 graph[u][v] = 1;
 graph[v][u] = 1;
 }
 printf("Enter starting vertex: ");
 scanf("%d", &s);
 DFS(s);
 BFS(s);
 return 0;
}
