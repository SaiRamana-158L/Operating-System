#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to search for a pattern in a file
void searchFile(const char *pattern, const char *filename) {
    FILE *file = fopen(filename, "r");

    // Check if the file opened successfully
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];

    // Read the file line by line and search for the pattern
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, pattern) != NULL) {
            printf("%s", line);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <pattern> <filename>\n", argv[0]);
        return 1;
    }

    const char *pattern = argv[1];
    const char *filename = argv[2];

    searchFile(pattern, filename);

    return 0;
}
