#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, seek_time = 0;

    // Get the number of disk requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int request_queue[n];

    // Get the disk request queue
    printf("Enter the disk request queue:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &request_queue[i]);
    }

    // Get the initial position of the disk head
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    // Sorting the request queue (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (request_queue[i] > request_queue[j]) {
                int temp = request_queue[i];
                request_queue[i] = request_queue[j];
                request_queue[j] = temp;
            }
        }
    }

    // SCAN (Elevator) Scheduling
    printf("\nSCAN (Elevator) Disk Scheduling:\n");
    printf("Head Movement Sequence: %d", head);

    int start = 0, end = n - 1;
    int current_direction = 1; // 1 for moving right, -1 for moving left

    while (start <= end) {
        if (current_direction == 1) { // Moving right
            for (int i = start; i <= end; i++) {
                if (request_queue[i] >= head) {
                    seek_time += abs(head - request_queue[i]);
                    head = request_queue[i];
                    printf(" -> %d", head);
                    start = i + 1;
                    break;
                }
            }
            current_direction = -1; // Change direction
        } else { // Moving left
            for (int i = end; i >= start; i--) {
                if (request_queue[i] <= head) {
                    seek_time += abs(head - request_queue[i]);
                    head = request_queue[i];
                    printf(" -> %d", head);
                    end = i - 1;
                    break;
                }
            }
            current_direction = 1; // Change direction
        }
    }

    // Print total and average seek time
    printf("\nTotal Seek Time: %d\n", seek_time);
    printf("Average Seek Time: %.2f\n", (float)seek_time / n);

    return 0;
}
