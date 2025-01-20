#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 100

// Function to get the maximum of two values
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using Dynamic Programming
int knapsack(int values[], int weights[], int n, int capacity) {
    int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1];
    int i,j,result,remaining_capacity;

    // Build the dp table
    for (i = 0; i <= n; i++) {
	for (j = 0; j <= capacity; j++) {
	    if (i == 0 || j == 0) {
		dp[i][j] = 0; // Base case: no items or zero capacity
	    } else if (weights[i - 1] <= j) {
		dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
	    } else {
		dp[i][j] = dp[i - 1][j];
	    }
	}
    }

    // Print selected items
    result = dp[n][capacity];
    remaining_capacity = capacity;
    printf("Selected items: ");
    for (i = n; i > 0 && result > 0; i--) {
	if (result != dp[i - 1][remaining_capacity]) {
	    // Item i-1 was included
	    printf("Item %d ", i);
	    result -= values[i - 1];
	    remaining_capacity -= weights[i - 1];
	}
    }
    printf("\n");

    return dp[n][capacity];
}

void main() {
    int n,i; // Number of items
    int capacity; // Knapsack capacity
    int max_value;
     int values[MAX_ITEMS], weights[MAX_ITEMS];


    printf("Enter the number of items: ");
    scanf("%d", &n);


   // int values[MAX_ITEMS], weights[MAX_ITEMS];
    // Input item values and weights
    for (i = 0; i < n; i++) {
	printf("Enter value of item %d: ", i + 1);
	scanf("%d", &values[i]);
	printf("Enter weight of item %d: ", i + 1);
	scanf("%d", &weights[i]);
    }

    // Input the knapsack capacity
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    // Solve the knapsack problem
    max_value = knapsack(values, weights, n, capacity);
    printf("Maximum value: %d\n", max_value);

getch();
}

