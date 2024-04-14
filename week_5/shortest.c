#include <stdio.h>

struct Process {
    int id;
    int burst_time;
};

void calculateTimes(struct Process processes[], int n) {
    int completion_time = 0;
    int total_turnaround_time = 0;
    int total_response_time = 0;

    for (int i = 0; i < n; i++) {
        completion_time += processes[i].burst_time;
        
        int turnaround_time = completion_time;
        total_turnaround_time += turnaround_time;
        
        int response_time = turnaround_time - processes[i].burst_time;
        total_response_time += response_time;

        printf("Process %d - Turnaround Time: %d, Response Time: %d\n", processes[i].id, turnaround_time, response_time);
    }

    float avg_turnaround_time = (float)total_turnaround_time / n;
    float avg_response_time = (float)total_response_time / n;

    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Response Time: %.2f\n", avg_response_time);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    calculateTimes(processes, n);

    return 0;
}