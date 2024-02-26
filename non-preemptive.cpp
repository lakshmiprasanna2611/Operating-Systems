#include<stdio.h>

struct Process {
    int pid; // Process ID
    int burst_time; // Burst Time
};

// Function to perform sorting based on burst time
void sort(struct Process *p, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].burst_time > p[j + 1].burst_time) {
                // Swap the processes
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

// Function to find waiting time for each process
void findWaitingTime(struct Process *p, int n, int *wt) {
    // Waiting time for first process is 0
    wt[0] = 0;

    // Calculate waiting time for remaining processes
    for (int i = 1; i < n; i++) {
        wt[i] = p[i - 1].burst_time + wt[i - 1];
    }
}

// Function to find turnaround time for each process
void findTurnaroundTime(struct Process *p, int n, int *wt, int *tat) {
    // Turnaround time for each process = Burst Time + Waiting Time
    for (int i = 0; i < n; i++) {
        tat[i] = p[i].burst_time + wt[i];
    }
}

// Function to find average time
void findAverageTime(struct Process *p, int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Sort processes based on burst time
    sort(p, n);

    // Find waiting time of all processes
    findWaitingTime(p, n, wt);

    // Find turnaround time of all processes
    findTurnaroundTime(p, n, wt, tat);

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Calculate average waiting time and average turnaround time
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;

    // Print results
    printf("Processes Burst Time Waiting Time Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, wt[i], tat[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        p[i].pid = i + 1;
    }

    findAverageTime(p, n);

    return 0;
}

/*output
Enter the number of processes: 1
Enter the burst time for each process:
Enter burst time for process 1: 2
Processes Burst Time Waiting Time Turnaround Time
1               2               0               2
Average Waiting Time: 0.00
Average Turnaround Time: 2.00
*/