#include <stdio.h>

// Function to print the adjacency matrix
void printAdjacencyMatrix(int maxVertices, int adjacencyMatrix[100][100]) {
    int i, j;
    printf("Adjacency Matrix of the Graph:\n");

    for (i = 0; i < maxVertices; i++) {
        for (j = 0; j < maxVertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void main() {
    int maxVertices, numEdges, i, j;
     int adjacencyMatrix[100][100];


    clrscr();
    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &maxVertices);

    adjacencyMatrix[maxVertices][maxVertices];

    // Initialize an adjacency matrix to store the graph
    //int adjacencyMatrix[maxVertices][maxVertices];

    // Initialize all elements in the adjacency matrix to 0
    for (i = 0; i < maxVertices; i++) {
	for (j = 0; j < maxVertices; j++) {
	    adjacencyMatrix[i][j] = 0;
	}
    }

    // Input number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (vertex pairs, e.g., 1 2):\n");
    // Input the edges and update the adjacency matrix
    for (i = 0; i < numEdges; i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);

        // Check if the vertices are within valid range
        if (vertex1 >= 1 && vertex1 <= maxVertices && vertex2 >= 1 && vertex2 <= maxVertices) {
            // Update the adjacency matrix for the undirected graph
            adjacencyMatrix[vertex1 - 1][vertex2 - 1] = 1;
            adjacencyMatrix[vertex2 - 1][vertex1 - 1] = 1;
        } else {
            printf("Invalid edge. Vertex numbers should be between 1 and %d.\n", maxVertices);
            i--; // Decrement the loop counter to re-enter the edge
        }
    }

    // Print the adjacency matrix
    printAdjacencyMatrix(maxVertices, adjacencyMatrix);
    
  getch();
}

