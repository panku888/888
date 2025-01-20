#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int c[MAX][MAX];      // Adjacency matrix
int visited[MAX];     // Visited array for BFS and DFS
int queue[MAX];       // Queue for BFS
int n;                // Number of vertices

// BFS function
void BFS(int v) {
    int front = 0, rear = -1, i;

    visited[v] = 1;
    queue[++rear] = v;  // Enqueue starting vertex

    while (front <= rear) {
        v = queue[front++];  // Dequeue vertex
        printf("%d ", v);

        // Traverse all adjacent vertices
        for (i = 1; i <= n; i++) {
            if (c[v][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;  // Enqueue adjacent vertex
                visited[i] = 1;     // Mark as visited
            }
        }
    }

    printf("\n");
}

// DFS function
void DFS(int v) {
    int i;

    visited[v] = 1;
    printf("%d ", v);

    // Traverse all adjacent vertices
    for (i = 1; i <= n; i++) {
	if (c[v][i] == 1 && visited[i] == 0) {
	    DFS(i);
	}
    }
}

void main() {
    int i, j, v;
    clrscr();
    // Input number of vertices
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the adjacency matrix of the graph:\n");
    for (i = 1; i <= n; i++) {
	for (j = 1; j <= n; j++) {
	    scanf("%d", &c[i][j]);
	}
    }

    // Initialize visited array for BFS
    for (i = 1; i <= n; i++) {
	visited[i] = 0;
    }

    // Perform BFS
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &v);
    printf("BFS traversal of the graph is: ");
    BFS(v);

    // Reset visited array for DFS
    for (i = 1; i <= n; i++) {
	visited[i] = 0;
    }

    // Perform DFS
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &v);
    printf("DFS traversal of the graph is: ");
    DFS(v);
    printf("\n");

getch();
}

