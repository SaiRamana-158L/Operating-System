#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;

    // Open file for writing
    file = fopen("example.txt", "w");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return 1;
    }

    // Writing data to the file
    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is a C file management example.\n");

    // Close the file
    fclose(file);

    // Open file for reading
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return 1;
    }

    // Reading data from the file
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);

    return 0;
}
