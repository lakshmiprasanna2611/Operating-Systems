#include<stdio.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
};

void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process processes[n];
    printf("Enter arrival time, burst time and priority for each process:\n");
    for (int i = 0; i < n; ++i) {
        printf("Process %d: ", i+1);
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
        processes[i].id = i+1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    // Sorting processes based on arrival time
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (processes[j].arrival_time > processes[j+1].arrival_time) {
                swap(&processes[j], &processes[j+1]);
            }
        }
    }

    int current_time = 0;
    int completed = 0;
    while (completed < n) {
        int highest_priority = -1;
        int selected_process = -1;
        for (int i = 0; i < n; ++i) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if (highest_priority == -1 || processes[i].priority < highest_priority) {
                    highest_priority = processes[i].priority;
                    selected_process = i;
                }
            }
        }
        if (selected_process == -1) {
            printf("CPU is idle at time %d\n", current_time);
            current_time++;
        } else {
            printf("Process %d is running at time %d\n", processes[selected_process].id, current_time);
            processes[selected_process].remaining_time--;

            if (processes[selected_process].remaining_time == 0) {
                completed++;
                printf("Process %d completed at time %d\n", processes[selected_process].id, current_time);
            }
            current_time++;
        }
    }

    return 0;
}

/*output
Enter the number of processes: 1
Enter arrival time, burst time and priority for each process:
Process 1: 4
5
5
CPU is idle at time 0
CPU is idle at time 1
CPU is idle at time 2
CPU is idle at time 3
Process 1 is running at time 4
Process 1 is running at time 5
Process 1 is running at time 6
Process 1 is running at time 7
Process 1 is running at time 8
Process 1 completed at time 8
*/