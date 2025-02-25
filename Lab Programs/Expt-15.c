#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char mainDirectory[] = "C:/SIMATS FILES/OPERATING SYSTEM PROGRAMS";
    char subDirectory[] = "Test Program";
    char fileName[] = "example.txt";
    char filePath[200];
    char mainDirPath[200];

    snprintf(mainDirPath, sizeof(mainDirPath), "%s/%s/", mainDirectory, subDirectory);
    snprintf(filePath, sizeof(filePath), "%s%s", mainDirPath, fileName);

    FILE *file = fopen(filePath, "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        return 1;
    }

    fprintf(file, "This is an example file content.");
    printf("File created successfully: %s\n", filePath);

    fclose(file);  // Ensure the file is properly closed
    return 0;
}
