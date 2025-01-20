#include <stdio.h>
//#include <stdbool.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0


// Structure to represent a job
struct Job {
    int profit;    // Profit of the job
    int deadline;  // Deadline of the job
    int id;        // Job ID
};

// Compare function for sorting jobs in decreasing order of profit
int compare(const void *a, const void *b) {
    const struct Job *jobA = (const struct Job *)a;
    const struct Job *jobB = (const struct Job *)b;
    return (jobB->profit - jobA->profit);  // Sort in descending order of profit
}

// Function to solve the Job Sequencing Problem
void jobSequencing(struct Job jobs[], int n) {
    int i, j;
    int timeSlots[100];
    int maxDeadline;
    int totalProfit;
    // Sort jobs in decreasing order of profit
    qsort(jobs, n, sizeof(struct Job), compare);

     maxDeadline = 0;
    // Find the maximum deadline to define the time slots
    for (i = 0; i < n; i++) {
	if (jobs[i].deadline > maxDeadline) {
	    maxDeadline = jobs[i].deadline;
	}
    }

    //int timeSlots[maxDeadline];
    for (i = 0; i < maxDeadline; i++) {
	timeSlots[i] = -1; // Initialize time slots to -1 (indicating empty)
    }

     totalProfit = 0;
    // Iterate over the jobs to schedule them
    for (i = 0; i < n; i++) {
        // Find a free slot for this job (starting from the last available slot)
        for (j = jobs[i].deadline - 1; j >= 0; j--) {
            if (timeSlots[j] == -1) {
                timeSlots[j] = i; // Assign the job to this time slot
                totalProfit += jobs[i].profit; // Add the profit to the total profit
                break; // Stop looking for other slots once the job is scheduled
            }
        }
    }
    
    // Print the job sequence
    printf("Job Sequence: ");
    for (i = 0; i < maxDeadline; i++) {
        if (timeSlots[i] != -1) {
            printf("Job%d ", jobs[timeSlots[i]].id);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

void main() {
    int n, i;
    struct Job jobs[100];

    clrscr();
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

   // struct Job jobs[n];

    printf("Enter job details (profit, deadline) for each job:\n");
    for (i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        scanf("%d %d", &jobs[i].profit, &jobs[i].deadline);
    }

    jobSequencing(jobs, n);

   getch();
}

