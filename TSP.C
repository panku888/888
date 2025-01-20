//2 Traveling sales man problem 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 10

int n;
int distances[MAX_CITIES][MAX_CITIES];
int memo[MAX_CITIES][1 << MAX_CITIES];
int parent[MAX_CITIES][1 << MAX_CITIES];

// Function to calculate the shortest TSP tour using dynamic programing
int tsp(int current, int visited) {

	int  minDistance = INT_MAX;
	 int next;
	 int newDistance;


    if (visited == (1 << n) - 1) {
	// All cities have been visited, return to the starting city
	return distances[current][0];
    }

    if (memo[current][visited] != -1) {
	return memo[current][visited];
    }



    for (next = 0; next < n; next++) {
	if (!(visited & (1 << next))) { // If the city is not visited
	    newDistance = distances[current][next] + tsp(next, visited | (1 << next));
	    if (newDistance < minDistance) {
		minDistance = newDistance;
		parent[current][visited] = next; // Update the parent
	    }
	}
    }

    memo[current][visited] = minDistance;
    return minDistance;
}

// Function to print the TSP route
void printRoute() {
    int current = 0;
    int visited = 1;
    int next;

    printf("Optimal Route: A");

    while (visited != (1 << n) - 1) {
	next = parent[current][visited];
	printf(" -> %c", 'A' + next);
	current = next;
	visited |= (1 << next);
    }

    printf(" -> A\n");
}

void main() {

	int i,j;
	int shortestDistance;
	clrscr();
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    if (n < 2 || n > MAX_CITIES) {
	printf("Please choose a number between 2 and %d.\n", MAX_CITIES);

    }

    printf("Enter the distances between cities (cost matrix row-wise):\n");
    for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
	    scanf("%d", &distances[i][j]);
	}
    }

    // Initialize memoization table with -1
    for (i = 0; i < n; i++) {
	for (j = 0; j < (1 << n); j++) {
	    memo[i][j] = -1;
	}
    }

    shortestDistance = tsp(0, 1); // Start from city 0 (A)
    printf("Shortest Distance: %d\n", shortestDistance);
    printRoute();

getch();
}

