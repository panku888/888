#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> // For gettimeofday()

// Function to partition the array
int partition(int A[], int low, int high) {
    int pivot, i, j, temp;
    pivot = A[low];
    i = low + 1;
    j = high;

    while (i <= j) {
        while (i <= high && A[i] <= pivot) i++;
        while (j >= low && A[j] > pivot) j--;

        if (i < j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

// Function to perform Quick Sort
void quicksort(int A[], int low, int high) {
    int j;
    if (low < high) {
        j = partition(A, low, high);
        quicksort(A, low, j - 1);
        quicksort(A, j + 1, high);
    }
}

void main() {
    int n, i, *A;
    struct timeval start, end;
    double time_taken;
  
    clrscr();
    printf("Enter the number of elements (n) or -999 to quit: ");
    scanf("%d", &n);

    while (n != -999) {
        if (n <= 0) {
            printf("Please enter a value greater than 0.\n");
        } else {
            // Dynamically allocate memory
            A = (int *)malloc(n * sizeof(int));
            if (A == NULL) { // Check if memory allocation failed
                printf("Memory allocation failed for %d elements. Try a smaller size.\n", n);
                //return 1;
            }

            // Generate random numbers for the array
            srand(time(NULL));
            for (i = 0; i < n; i++) {
                A[i] = rand() % 100000; // Random numbers between 0 and 99999
            }

            // Start timer
            gettimeofday(&start, NULL);

            // Perform Quick Sort
            quicksort(A, 0, n - 1);

            // End timer
            gettimeofday(&end, NULL);

            // Calculate time in seconds
            time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;

            printf("Time taken to sort %d elements: %.6f seconds\n", n, time_taken);

            // Free allocated memory
            free(A);
        }

        printf("Enter the number of elements (n) or -999 to quit: ");
        scanf("%d", &n);
    }

   getch();
}

