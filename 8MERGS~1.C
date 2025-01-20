//8 merge sort  
#include <stdio.h>

// Merge function to merge two subarrays of A[]
void Merge(int A[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int c[10];  // Temporary array for merging

    // Merge the two subarrays
    while (i <= mid && j <= high) {
        if (A[i] <= A[j]) {
            c[k] = A[i];
            i++;
        } else {
            c[k] = A[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements from the left subarray (if any)
    while (i <= mid) {
        c[k] = A[i];
        i++;
        k++;
    }

    // Copy the remaining elements from the right subarray (if any)
    while (j <= high) {
        c[k] = A[j];
        j++;
        k++;
    }

    // Copy the merged elements back to the original array
    for (i = low; i <= high; i++) {
        A[i] = c[i];
    }
}

// MergeSort function to recursively divide and sort the array
void MergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        // Recursively divide the array into two halves
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);

        // Merge the two sorted halves
        Merge(A, low, mid, high);
    }
}

void main() {
    int n, i;
    int A[10];  // Array to store the elements
    clrscr();
    // Input the number of elements
    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
	scanf("%d", &A[i]);
    }

    // Perform MergeSort on the array
    MergeSort(A, 0, n - 1);

    // Output the sorted array
    printf("Sorted list of elements: ");
    for (i = 0; i < n; i++) {
	printf("%d ", A[i]);
    }
    printf("\n");


    getch();

    }

