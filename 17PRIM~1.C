#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// Function to find the vertex with the minimum key value
int minkey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index;
    int v;
    for (v = 0; v < n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the MST and return the total weight
int printMST(int parent[], int c[][10], int n) {
    int totalweight = 0;
    int i;
    printf("Edge Weight\n");
    for (i = 1; i < n; i++) {
        printf("%d %d %d\n", parent[i] + 1, i + 1, c[i][parent[i]]);
        totalweight += c[i][parent[i]];
    }
    return totalweight;
}

// Function to implement Prim's algorithm for MST
void primMST(int c[][10], int n) {
    int parent[100];
    int key[100];
    int mstSet[100];
    int totalweight;
    int v,u,i,count;
    
    for (i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;

    for (count = 0; count < n - 1; count++) {
           u = minkey(key, mstSet, n);
        mstSet[u] = 1;

        for (v = 0; v < n; v++) {
            if (c[u][v] && mstSet[v] == 0 && c[u][v] < key[v]) {
                parent[v] = u;
                key[v] = c[u][v];
            }
        }
    }
      totalweight = printMST(parent, c, n);
    printf("Total cost of the minimum spanning tree: %d\n", totalweight);
}

void main() {
    int n,i,j;
    int c[100][10];


    printf("Enter the number of vertices: ");
    scanf("%d", &n);


    
    printf("Enter the cost adjacency matrix:\n");

    for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    primMST(c, n);

getch();
}

