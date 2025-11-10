#include <stdio.h>
#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n;

void createGraph() {
    int i, j;
    printf("Enter number of cities (nodes): ");
    scanf("%d", &n);
    printf("\nEnter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
}

void DFS(int v) {
    int i;
    printf("%d ", v);
    visited[v] = 1;
    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i])
            DFS(i);
    }
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    int i, v;
    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("%d ", start);
    visited[start] = 1;
    queue[rear++] = start;
    while (front < rear) {
        v = queue[front++];
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int choice, start;
    printf("---- Graph Operations ----\n");
    do {
        printf("\n1. Create Graph\n2. Display Reachable Nodes (DFS)\n3. Display Reachable Nodes (BFS)\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            createGraph();
            break;
        case 2:
            for (int i = 0; i < n; i++)
                visited[i] = 0;
            printf("Enter starting node: ");
            scanf("%d", &start);
            printf("Nodes reachable from %d (DFS): ", start);
            DFS(start);
            printf("\n");
            break;
        case 3:
            printf("Enter starting node: ");
            scanf("%d", &start);
            printf("Nodes reachable from %d (BFS): ", start);
            BFS(start);
            printf("\n");
            break;
        case 4:
            printf("Exiting Program.\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);
    return 0;
}
