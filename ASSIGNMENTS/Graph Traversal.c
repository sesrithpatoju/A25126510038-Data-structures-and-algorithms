#include <stdio.h>
int main() 
{
    int n, start;
    printf("Enter number of locations: ");
    scanf("%d", &n);
    int adj[n][n], visited[n], queue[n];
    int front = 0, rear = 0;
    for(int i = 0; i < n; i++) 
    {
        visited[i] = 0;
    }
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);
    printf("Visited order starting from %d: ", start);
    visited[start] = 1;
    queue[rear++] = start;
    while(front < rear)
    {
        int curr = queue[front++];
        printf("%d ", curr);
        for(int i = 0; i < n; i++) 
        {
            if(adj[curr][i] != 0 && visited[i] == 0) 
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    for(int i = 0; i < n; i++) 
    {
        if(visited[i] == 0) 
        {
            printf("\nGraph partially connected. Traversing unreached from %d: ", i);
            visited[i] = 1;
            queue[rear++] = i;
            while(front < rear) 
            {
                int curr = queue[front++];
                printf("%d ", curr);
                for(int j = 0; j < n; j++) 
                {
                    if(adj[curr][j] != 0 && visited[j] == 0) 
                    {
                        visited[j] = 1;
                        queue[rear++] = j;
                    }
                }
            }
        }
    }
    printf("\n");
    return 0;
}
