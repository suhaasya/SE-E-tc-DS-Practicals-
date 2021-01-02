/*
Assignment no- 6
Title of program-   Implement Graph using adjacency Matrix with BFS & DFS traversal.
(DFS)
*/
#include<stdio.h>

int a[20][20],q[20],visited[20],n;

void dfs(int v)
{
       int i;
       for (i=0;i<n;i++)                                // check all the vertices in the graph
       {
               if(a[v][i] != 0 && visited[i] == 0) // adjacent to v and not visited
              {
                       visited[i]=1;          // mark the vertex visited
                       printf("%d  ",i);
                       dfs(i);
              }
      }
}
int main()
{
    int v,i,j;
    printf("\n Enter the number of vertices:");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        visited[i]=0;
    }
    printf("\n Enter graph data in matrix form:\n");
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
       scanf("%d",&a[i][j]);
    printf("\n Enter the starting vertex:");
    scanf("%d",&v);
    printf("\n DFS traversal is:\n");
    visited[v]=1; // mark the starting vertex as visited
    printf("%d   ",v);

    dfs(v);
}
