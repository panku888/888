#include <stdio.h>
#include <math.h>


typedef int bool;
#define true 1
#define false 0


#define MAX_N 28

int x[MAX_N]; // Solution vector to store column positions of queens

// Function to check if it's safe to place a queen at kth row and ith column
bool place(int k, int i) {
    int j;
    for (j = 1; j < k; j++) {
        // Check if queens are in the same column or diagonal
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

// Function to print the solution
void printSolution(int n) {
    int i;
    for (i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

// Function to solve the N Queens problem using backtracking
void NQueens(int k, int n) {
    int i;
    for (i = 1; i <= n; i++) {
	if (place(k, i)) {
            x[k] = i;  // Place the queen in the current column
            if (k == n) {
                printSolution(n);  // All queens are placed, print the solution
            } else {
                NQueens(k + 1, n);  // Recursively place queens in the next row
            }
        }
    }
}

void main() {
    int n, i;
    
    clrscr();

    printf("Enter the value of N (number of queens): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_N) {
        printf("Invalid input. N should be between 1 and %d.\n", MAX_N);

    }

    // Initialize the solution vector
    for (i = 1; i <= n; i++) {
        x[i] = 0;
    }

    printf("Solutions for the N Queens problem:\n");
    NQueens(1, n);  // Start solving from the first row

    getch();
}

