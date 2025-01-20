#include <stdio.h>
#include <stdlib.h>

void knapsackGreedy(int M, int n, int w[], int P[]) {
    int i, j;                  // Loop variables
    int currentIndex;          // Index of the current object
    int tempIndex;             // Temporary index for sorting
    int remainingCapacity;     // Remaining capacity of the knapsack
    double *ratio;             // Profit-to-weight ratio for each object
    double *x;                 // Solution vector
    double sum = 0.0;          // Total profit
    int *order;                // Array to store the order of objects

    // Dynamically allocate memory for arrays
    ratio = (double *)malloc(n * sizeof(double));
    x = (double *)malloc(n * sizeof(double));
    order = (int *)malloc(n * sizeof(int));

    // Calculate profit-to-weight ratio for each object
    for (i = 0; i < n; i++) {
        ratio[i] = (double)P[i] / w[i];
        order[i] = i; // Initialize order array
    }

    // Sort the objects in descending order of profit-to-weight ratio
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ratio[order[j]] < ratio[order[j + 1]]) {
                // Swap the order indices
                tempIndex = order[j];
                order[j] = order[j + 1];
                order[j + 1] = tempIndex;
            }
        }
    }

    // Initialize solution vector and remaining capacity
    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }
    remainingCapacity = M;

    // Select objects based on the greedy strategy
    for (i = 0; i < n; i++) {
        currentIndex = order[i];
        if (w[currentIndex] <= remainingCapacity) {
            x[currentIndex] = 1.0; // Take the whole object
            remainingCapacity -= w[currentIndex];
            sum += P[currentIndex];
        } else {
            x[currentIndex] = (double)remainingCapacity / w[currentIndex]; // Take fraction of the object
            sum += P[currentIndex] * x[currentIndex];
            break; // Knapsack is full
        }
    }

    // Display the solution vector and the maximum profit
    printf("Solution vector 'x': ");
    for (i = 0; i < n; i++) {
        printf("%.2f ", x[i]);
    }
    printf("\nMaximum Profit: %.2f\n", sum);

    // Free allocated memory
    free(ratio);
    free(x);
    free(order);
}

void main() {
    int M;         // Knapsack capacity
    int n;         // Number of objects
    int i;         // Loop variable
    int *w;        // Weights of the objects
    int *P;        // Profits of the objects
    clrscr();
    // Input Knapsack capacity "M" and the number of objects "n"
    printf("Enter Knapsack capacity (M): ");
    scanf("%d", &M);

    printf("Enter the number of objects (n): ");
    scanf("%d", &n);

    // Dynamically allocate memory for weights and profits arrays
    w = (int *)malloc(n * sizeof(int));
    P = (int *)malloc(n * sizeof(int));

    // Input weights and profits for each object
    printf("Enter weights for each object:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter profits for each object:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &P[i]);
    }

    // Call the knapsackGreedy function to find the solution
    knapsackGreedy(M, n, w, P);

    // Free allocated memory
    free(w);
    free(P);
getch();
}

