//7 Quick sort using divide and conquer mathod

#include <stdio.h>

// Function to perform partitioning of the array
int partition(int A[], int low, int high) {
    int pivot = A[low];  // Select the first element as the pivot
    int i = low, j = high;
    int temp;

    while (i < j) {
        // Increment i while elements are smaller than the pivot
        while (A[i] <= pivot && i <= high) {
            i++;
        }
        // Decrement j while elements are greater than the pivot
        while (A[j] > pivot && j >= low) {
            j--;
        }

        if (i < j) {
            // Swap A[i] and A[j] if they are not in the correct position
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    // Swap pivot with A[j] to put pivot in its correct position
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;  // Return pivot's final index
}

// Function to perform Quick Sort
void quicksort(int A[], int low, int high) {
    if (low < high) {
        int j = partition(A, low, high);  // Partition the array
        quicksort(A, low, j - 1);  // Recursively sort the left sub-array
        quicksort(A, j + 1, high); // Recursively sort the right sub-array
    }
}

void main() {
    int n, i;
    int A[10];  // Array to store the elements
    clrscr();
    // Input the number of elements
    printf("Enter the number of elements of array: ");
    scanf("%d", &n);

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
	scanf("%d", &A[i]);
    }

    // Perform quicksort on the array
    quicksort(A, 0, n - 1);

    // Output the sorted array
    printf("Sorted list of elements: ");
    for (i = 0; i < n; i++) {
	printf("%d ", A[i]);
    }
    printf("\n");

    getch();
}

