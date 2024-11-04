#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int adjMatrix[MAX][MAX], visited[MAX], n;
char nodes[MAX];

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    printf("BFS Traversal: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%c ", nodes[node]);
        for (int i = 0; i < n; i++) {
            if (adjMatrix[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void DFS(int start) {
    int stack[MAX], top = -1;
    stack[++top] = start;
    printf("DFS Traversal: ");
    while (top != -1) {
        int node = stack[top--];
        if (!visited[node]) {
            visited[node] = 1;
            printf("%c ", nodes[node]);
            for (int i = n - 1; i >= 0; i--) {
                if (adjMatrix[node][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
    printf("\n");
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the node labels (e.g., A B C ...): ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &nodes[i]);
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    int start;
    printf("Enter the starting node number (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting node.\n");
        return 1;
    }

    memset(visited, 0, sizeof(visited));  // Reset visited array
    BFS(start);

    memset(visited, 0, sizeof(visited));  // Reset visited array again
    DFS(start);

    return 0;
}
