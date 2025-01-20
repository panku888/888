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

// Function to print in-degree and out-degree for each vertex
void printDegree(int maxVertices, int adjacencyMatrix[100][100]) {
    int i, j;
     int inDegree,outDegree;
    
    for (i = 0; i < maxVertices; i++) {
         inDegree = 0, outDegree = 0;
        
        // Calculate out-degree
        for (j = 0; j < maxVertices; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                outDegree++;
            }
        }
        
        // Calculate in-degree
        for (j = 0; j < maxVertices; j++) {
            if (adjacencyMatrix[j][i] == 1) {
                inDegree++;
            }
        }

        printf("Vertex %d: In-Degree %d, Out-Degree %d\n", i + 1, inDegree, outDegree);
    }
}

void main() {
    int maxVertices, numEdges, i, j;
     int vertex1, vertex2;
     int adjacencyMatrix[100][100];
     
     clrscr();

    printf("Enter the number of vertices: ");
    scanf("%d", &maxVertices);

    // Initialize an adjacency matrix to store the graph
   // adjacencyMatrix[maxVertices][maxVertices];

    // Initialize all elements in the adjacency matrix to 0
    for (i = 0; i < maxVertices; i++) {
        for (j = 0; j < maxVertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (vertex pairs, e.g., 1 2):\n");

    // Input the edges and update the adjacency matrix
    for (i = 0; i < numEdges; i++) {
       // int vertex1, vertex2;
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

    // Print in-degree and out-degree for each vertex
    printDegree(maxVertices, adjacencyMatrix);

    getch();
}

