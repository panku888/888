#include <stdio.h>
#include <limits.h>

#define MAX_KEYS 100

// Function to calculate the optimal binary search tree
double optimalBST( double P[], int n) {
    float C[MAX_KEYS+1][MAX_KEYS+1];
    float R[MAX_KEYS + 1][MAX_KEYS + 1];
    int i, j, d, x, k;

    double minval ;
    double sum = 0;
     double cvalue;

    // Initialize Cost and Root Tables
    for (i = 1; i <= n; i++) {
	C[i][i - 1] = 0;
	C[i][i] = P[i];
	R[i][i] = i;
    }
    C[n + 1][n] = 0;

    for (d = 1; d <= n - 1; d++) {
	for (i = 1; i <= n - d; i++) {
	    j = i + d;
		minval = INT_MAX;
	    for (k = i; k <= j; k++) {
		     sum = 0;
		for (x = i; x <= j; x++) sum += P[x];
		    cvalue = C[i][k - 1] + C[k + 1][j] + sum;
		if (cvalue < minval) {
		    minval = cvalue;
		    R[i][j] = k;
		}
	    }
	    C[i][j] = minval;
	}
    }

    // Printing the Cost Table
    printf("The Cost Table is:\n");
    for (i = 1; i <= n; i++) {
	for (j = 1; j <= n; j++) {
	    printf("%.2f\t", C[i][j]);
	}
	printf("\n");
    }

    // Printing the Cost of the Optimal Binary Search Tree
    printf("The Cost of the Optimal Binary Search Tree is: %.2f\n", C[1][n]);

    return 0;
}

void main() {
    int n;
    int i,keys[MAX_KEYS];
    double P[MAX_KEYS];

    clrscr();

    printf("Enter the number of keys: ");
    scanf("%d", &n);



    printf("Enter the keys and their search probabilities:\n");
    for (i = 1; i <= n; i++) {
	scanf("%d %lf", &keys[i], &P[i]);
    }

    optimalBST(P, n);

    getch();
}

