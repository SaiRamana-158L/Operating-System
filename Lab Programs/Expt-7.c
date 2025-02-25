#include <stdio.h>

int main() {
    int at[10], bt[10], pr[10];
    int n, i, j, temp, time = 0, count, over = 0, sum_wait = 0, sum_turnaround = 0, start;
    float avgwait, avgturn;

    // Input: Number of Processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input: Arrival Time & Burst Time
    for (i = 0; i < n; i++) {
        printf("Enter the arrival time and execution time for process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        pr[i] = i + 1; // Storing process number
    }

    // Sorting processes based on Arrival Time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                // Swap Arrival Time
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap Burst Time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap Process Number
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
            }
        }
    }

    // Display Table Header
    printf("\n\nProcess\t| Arrival Time\t| Execution Time\t| Start Time\t| End Time\t| Waiting Time\t| Turnaround Time\n\n");

    // Scheduling Logic
    while (over < n) {
        count = 0;

        // Count number of available processes at the current time
        for (i = over; i < n; i++) {
            if (at[i] <= time)
                count++;
            else
                break;
        }

        // Sort processes based on Burst Time if multiple processes are available
        if (count > 1) {
            for (i = over; i < over + count - 1; i++) {
                for (j = i + 1; j < over + count; j++) {
                    if (bt[i] > bt[j]) {
                        // Swap Arrival Time
                        temp = at[i];
                        at[i] = at[j];
                        at[j] = temp;

                        // Swap Burst Time
                        temp = bt[i];
                        bt[i] = bt[j];
                        bt[j] = temp;

                        // Swap Process Number
                        temp = pr[i];
                        pr[i] = pr[j];
                        pr[j] = temp;
                    }
                }
            }
        }

        // Process Execution
        start = time;
        time += bt[over];

        printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",
               pr[over], at[over], bt[over], start, time, time - at[over] - bt[over], time - at[over]);

        // Calculate Waiting Time & Turnaround Time
        sum_wait += time - at[over] - bt[over];
        sum_turnaround += time - at[over];
        over++;
    }

    // Calculate Averages
    avgwait = (float)sum_wait / (float)n;
    avgturn = (float)sum_turnaround / (float)n;

    // Display Average Waiting Time & Turnaround Time
    printf("\nAverage Waiting Time: %.2f", avgwait);
    printf("\nAverage Turnaround Time: %.2f\n", avgturn);

    return 0;
}
