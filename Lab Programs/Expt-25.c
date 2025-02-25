#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

extern int errno;

int main() {
    int fd = open("foo.txt", O_RDONLY | O_CREAT, 0644); // Added file permissions

    printf("fd = %d\n", fd);

    if (fd == -1) {
        printf("Error Number: %d\n", errno);
        perror("Program");
        exit(EXIT_FAILURE); // Exiting with failure status
    }

    close(fd); // Closing the file descriptor
    return 0;
}
