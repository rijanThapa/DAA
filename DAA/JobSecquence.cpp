#include <stdio.h>
#include <stdlib.h>

struct Job {
    char id;
    int deadline;
    int profit;
};

int compare_jobs(const void *a, const void *b) {
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

int find_max_deadline(struct Job jobs[], int n) {
    int max_deadline = 0;
    for (int i = 0; i < n; ++i) {
        if (jobs[i].deadline > max_deadline) {
            max_deadline = jobs[i].deadline;
        }
    }
    return max_deadline;
}

void job_sequencing(struct Job jobs[], int n) {
    qsort(jobs, n, sizeof(struct Job), compare_jobs);
    
    int max_deadline = find_max_deadline(jobs, n);
    
    char result[max_deadline];
    int slot[max_deadline];
    
    for (int i = 0; i < max_deadline; ++i) {
        slot[i] = -1;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = jobs[i].deadline - 1; j >= 0; --j) {
            if (slot[j] == -1) {
                slot[j] = i;
                result[j] = jobs[i].id;
                break;
            }
        }
    }
    
    printf("Optimal Job Sequence is: ");
    for (int i = 0; i < max_deadline; ++i) {
        if (slot[i] != -1) {
            printf("%c ", result[i]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    
    struct Job jobs[n];
    
    for (int i = 0; i < n; ++i) {
        printf("Enter details for Job %d:\n", i + 1);
        printf("ID: ");
        scanf(" %c", &jobs[i].id);
        printf("Deadline: ");
        scanf("%d", &jobs[i].deadline);
        printf("Profit: ");
        scanf("%d", &jobs[i].profit);
    }
    
    printf("\nGiven Jobs:\n");
    for (int i = 0; i < n; ++i) {
        printf("Job %c: Deadline = %d, Profit = %d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }
    
    job_sequencing(jobs, n);
    
    return 0;
}

