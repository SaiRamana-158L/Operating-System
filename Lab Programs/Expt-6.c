#include <stdio.h>

int main() {
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0;
    int at[10], bt[10], temp[10];
    float avg_wt, avg_tat;

    // Input: Number of processes
    printf("Total number of processes in the system: ");
    scanf("%d", &NOP);
    y = NOP; // Number of processes left to execute

    // Input: Arrival Time & Burst Time for each process
    for (i = 0; i < NOP; i++) {
        printf("\nEnter the Arrival and Burst time of Process[%d]\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i]; // Copy burst time to temp array for processing
    }

    // Input: Time Quantum
    printf("Enter the Time Quantum for the process: ");
    scanf("%d", &quant);

    printf("\nProcess No \t Burst Time \t Turnaround Time \t Waiting Time");

    // Round Robin Scheduling Logic
    for (sum = 0, i = 0; y != 0; ) {
        if (temp[i] <= quant && temp[i] > 0) {
            sum += temp[i];
            temp[i] = 0;
            count = 1;
        } else if (temp[i] > 0) {
            temp[i] -= quant;
            sum += quant;
        }

        if (temp[i] == 0 && count == 1) {
            y--; // Process completed
            printf("\nProcess[%d] \t %d \t\t %d \t\t\t %d",
                   i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt += sum - at[i] - bt[i]; // Waiting Time
            tat += sum - at[i]; // Turnaround Time
            count = 0;
        }

        // Cycle through processes in round robin order
        if (i == NOP - 1) {
            i = 0;
        } else if (at[i + 1] <= sum) {
            i++;
        } else {
            i = 0;
        }
    }

    // Calculating Average Waiting Time & Turnaround Time
    avg_wt = (float)wt / NOP;
    avg_tat = (float)tat / NOP;

    // Displaying Average Times
    printf("\n\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}
