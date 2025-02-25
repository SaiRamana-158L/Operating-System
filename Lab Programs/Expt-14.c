#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void copy() {
    const char *sourcefile = "C:/SIMATS FILES/PERATING SYSTEM PROGRAMS/SAI.txt";
    const char *destination_file = "C:/SIMATS FILES/OPERATING SYSTEM PROGRAMS/SA.txt";

    int source_fd = open(sourcefile, O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        return;
    }

    int dest_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dest_fd == -1) {
        perror("Error opening destination file");
        close(source_fd);
        return;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead, bytesWritten;

    while ((bytesRead = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytesWritten = write(dest_fd, buffer, bytesRead);
        if (bytesWritten == -1) {
            perror("Error writing to file");
            close(source_fd);
            close(dest_fd);
            return;
        }
    }

    close(source_fd);
    close(dest_fd);
    printf("File copied successfully.\n");
}

void create() {
    FILE *fp = fopen("C:/SIMATS FILES/OPERATING SYSTEM PROGRAMS/SAI.txt", "w");
    if (fp == NULL) {
        perror("Error creating file");
        return;
    }
    fclose(fp);
    printf("File created successfully.\n");
}

void delete_file() {
    if (remove("C:/SIMATS FILES/OPERATING SYSTEM PROGRAMS/SAI.txt") == 0) {
        printf("File deleted successfully.\n");
    } else {
        perror("Error deleting file");
    }
}

int main() {
    int n;
    printf("1. Create \t2. Copy \t3. Delete\nEnter your choice: ");
    scanf("%d", &n);

    switch (n) {
        case 1:
            create();
            break;
        case 2:
            copy();
            break;
        case 3:
            delete_file();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
