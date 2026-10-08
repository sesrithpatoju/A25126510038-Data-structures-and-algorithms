#include <stdio.h>
int main() 
{
    int n, src, u, min;
    printf("Enter number of cities: ");
    scanf("%d", &n);
    int cost[n][n], dist[n], visited[n];
    printf("Enter cost matrix (0 for no road):\n");
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            scanf("%d", &cost[i][j]);
        }
    }
    printf("Enter city: ");
    scanf("%d", &src);
    for(int i = 0; i < n; i++) 
    {
        dist[i] = 9999;
        visited[i] = 0;
    }
    dist[src] = 0;
    for(int step = 0; step < n - 1; step++) 
    {
        min = 9999;
        u = -1;
        for(int i = 0; i < n; i++) 
        {
            if(visited[i] == 0 && dist[i] < min) 
            {
                min = dist[i];
                u = i;
            }
        }
        if(u == -1) break;
        visited[u] = 1;
        for(int v = 0; v < n; v++) 
        {
            if(!visited[v] && cost[u][v] != 0 && dist[u] + cost[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }
    printf("\nDestination\tShortest Distance\n");
    for(int i = 0; i < n; i++) 
    {
        printf("%d -> %d\t\t%d\n", src, i, dist[i]);
    }
    return 0;
}
