#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare a global temporary array
int *temp;

// Function to merge two subarrays into a sorted array
void merge(int arr[], int left, int mid, int right) {
    int i, j, k; // Declare variables at the beginning

    i = left;
    j = mid + 1;
    k = left;

    // Merge the two halves into temp
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements from the left half
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from the right half
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the merged elements back into the original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    int mid; // Declare variable at the beginning

    if (left < right) {
        mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to generate an array of random integers
void generateArray(int arr[], int size) {
    int i; // Declare variable at the beginning
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100000; // Random numbers between 0 and 99,999
    }
}

void main() {
    int sizes[] = {5000, 10000,6000,7000}; // Array sizes
    int numSizes;                                      // Number of sizes
    int *arr;                                          // Pointer for the main array
    int n, i;                                          // Variables for sizes and iteration
    clock_t start, end;                                // Variables for timing
    double timeTaken;                                  // Variable to store elapsed time

    numSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (i = 0; i < numSizes; i++) {
        n = sizes[i];

        // Allocate memory for the array
        arr = (int *)malloc(n * sizeof(int));
	temp = (int *)malloc(n * sizeof(int));
      clrscr();
	if (arr == NULL || temp == NULL) {
	    printf("Memory allocation failed for size %d\n", n);


	}

	// Generate random array
	generateArray(arr, n);

	// Record the start time
	start = clock();

	// Sort the array
	mergeSort(arr, 0, n - 1);

	// Record the end time
	end = clock();

	// Calculate elapsed time
	timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Time taken to sort array of size %d: %f seconds\n", n, timeTaken);

	// Free allocated memory
	free(arr);
	free(temp);
    }

getch();
}

