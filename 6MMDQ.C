// Find minimum and maximum using divide and conquer method
#include <stdio.h>

// Function to find the minimum and maximum values using divide and conquer
void findMinMax(int arr[], int start, int end, int *min, int *max) {
    int mid, min1, max1, min2, max2; // Declare all variables at the beginning

    if (start == end) {
        // Array contains only one element
        *min = *max = arr[start];
        return;
    }

    if (end == start + 1) {
        // Array contains two elements
        if (arr[start] < arr[end]) {
            *min = arr[start];
            *max = arr[end];
        } else {
            *min = arr[end];
            *max = arr[start];
        }
        return;
    }

    // Divide the array into two halves
    mid = (start + end) / 2;

    // Recursively find the minimum and maximum in both halves
    findMinMax(arr, start, mid, &min1, &max1);
    findMinMax(arr, mid + 1, end, &min2, &max2);

    // Combine the results from the two halves
    *min = (min1 < min2) ? min1 : min2;
    *max = (max1 > max2) ? max1 : max2;
}

void main() {
    int n, i, min, max; // Declare all variables at the beginning
    int arr[100];       // Declare array at the beginning with a fixed size
    clrscr();
    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input the array elements
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
	scanf("%d", &arr[i]);
    }

    // Find the minimum and maximum values using divide and conquer
    findMinMax(arr, 0, n - 1, &min, &max);

    // Output the results
    printf("Minimum value in the array: %d\n", min);
    printf("Maximum value in the array: %d\n", max);

    getch();

}

