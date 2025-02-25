#include <stdio.h>

// Structure to store process details
struct priority_scheduling {
    char process_name;
    int burst_time;
    int waiting_time;
    int turn_around_time;
    int priority;
};

int main() {
    int number_of_process, total = 0;
    struct priority_scheduling temp_process;
    int ASCII_number = 65; // ASCII 'A' for process names
    int position;
    float average_waiting_time, average_turnaround_time;

    // Input: Number of processes
    printf("Enter the total number of processes: ");
    scanf("%d", &number_of_process);

    struct priority_scheduling process[number_of_process];

    // Input: Burst Time and Priority for each process
    printf("\nPlease enter the Burst Time and Priority of each process:\n");
    for (int i = 0; i < number_of_process; i++) {
        process[i].process_name = (char)ASCII_number;
        printf("\nEnter the details of process %c \n", process[i].process_name);
        printf("Enter the burst time: ");
        scanf("%d", &process[i].burst_time);
        printf("Enter the priority: ");
        scanf("%d", &process[i].priority);
        ASCII_number++;
    }

    // Sorting processes based on priority (Higher priority first)
    for (int i = 0; i < number_of_process; i++) {
        position = i;
        for (int j = i + 1; j < number_of_process; j++) {
            if (process[j].priority > process[position].priority) {
                position = j;
            }
        }
        // Swapping process details
        temp_process = process[i];
        process[i] = process[position];
        process[position] = temp_process;
    }

    // Calculating Waiting Time
    process[0].waiting_time = 0;
    for (int i = 1; i < number_of_process; i++) {
        process[i].waiting_time = 0;
        for (int j = 0; j < i; j++) {
            process[i].waiting_time += process[j].burst_time;
        }
        total += process[i].waiting_time;
    }

    // Calculating Average Waiting Time
    average_waiting_time = (float)total / number_of_process;
    total = 0;

    // Output: Process details
    printf("\n\nProcess Name \t Burst Time \t Waiting Time \t Turnaround Time\n");
    for (int i = 0; i < number_of_process; i++) {
        process[i].turn_around_time = process[i].burst_time + process[i].waiting_time;
        total += process[i].turn_around_time;
        printf("\t %c \t\t %d \t\t %d \t\t %d\n",
               process[i].process_name,
               process[i].burst_time,
               process[i].waiting_time,
               process[i].turn_around_time);
    }

    // Calculating Average Turnaround Time
    average_turnaround_time = (float)total / number_of_process;

    // Output: Average Waiting Time and Turnaround Time
    printf("\n\nAverage Waiting Time: %.2f", average_waiting_time);
    printf("\nAverage Turnaround Time: %.2f\n", average_turnaround_time);

    return 0;
}
