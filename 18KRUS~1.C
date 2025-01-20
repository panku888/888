#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX_VERTICES 9

int i, j, k, a, b, u, v, n, ne = 1;
int mincost=0, cost[MAX_VERTICES][MAX_VERTICES], parent[MAX_VERTICES];

int find(int vertex) {
    while (parent[vertex]) {
	vertex = parent[vertex];
    }
    return vertex;
}

int unionSets(int set1, int set2) {
    if (set1 != set2) {
	parent[set2] = set1;
	return 1;
    }
    return 0;
}

void kruskalsAlgorithm() {
int min;
    printf("The edges of the Minimum Cost Spanning Tree are:\n");

    while (ne < n) {
	   min = 999;
	for (i = 1; i <= n; i++) {
	    for (j = 1; j <= n; j++) {
		if (cost[i][j] < min) {
		    min = cost[i][j];
		    a = u = i;
		    b = v = j;
		}
	    }
	}

	u = find(u);
	v = find(v);

	if (unionSets(u, v)) {
	    printf("Edge (%d, %d) = %d\n", ne++,a , b, min);
	    mincost += min;

	}

	cost[a][b] = cost[b][a] = 999;  // Set the edge to a large number after processing
    }

    printf("Minimum cost = %d\n", mincost);
}

void main() {

    clrscr();
    printf("\n\tImplementation of Kruskal's Algorithm\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <=n; i++) {
	for (j = 1; j <= n; j++) {
	    scanf("%d", &cost[i][j]);
	    if (cost[i][j] == 0) {
		cost[i][j] = 999;  // No connection between nodes
	    }
	}
    }

    kruskalsAlgorithm();
    printf("Minimum cost = %d\n", mincost);

    getch();

}

