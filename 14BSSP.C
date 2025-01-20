#include <stdio.h>

int w[10], d, n, count, x[10],i;

// Function to find the sum of subsets
void sum_of_subsets(int s, int k, int r) {
    x[k] = 1;

    // If the current subset sum equals the desired sum, print it
    if (s + w[k] == d) {
        printf("\nSubset %d: ", ++count);
	for (i = 0; i <= k; i++) {
	    if (x[i]) {
		printf("%d ", w[i]);
	    }
	}
	printf("\n");
    }

    // If the current sum plus the remaining elements is still less than the desired sum
    else if (s +w[k]+w[k+1] <= d) {
	sum_of_subsets(s + w[k], k + 1, r - w[k]);
    }

    // If we can't include the current element, try excluding it
    if (s + r - w[k] >= d && (s + w[k+1] <= d))
     {
	x[k] = 0;
	sum_of_subsets(s, k + 1, r - w[k]);
    }
}

void main() {
    int sum = 0;


    clrscr();
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements in ascending order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter the sum: ");
    scanf("%d", &d);

    for (i = 0; i < n; i++) {
        sum += w[i];
    }

    // Start the backtracking process
    printf("Possible subsets are:\n");
    sum_of_subsets(0, 0, sum);

   getch();
}

