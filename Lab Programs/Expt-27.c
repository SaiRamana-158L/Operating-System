#include <stdio.h>
#include <string.h>

int main() {
    char fn[100], pat[100], temp[200];
    FILE *fp;

    // Get the file name from the user
    printf("\nEnter file name: ");
    scanf("%s", fn);

    // Get the pattern to search for
    printf("Enter the pattern: ");
    scanf("%s", pat);

    // Open the file for reading
    fp = fopen(fn, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read and search for the pattern line by line
    while (fgets(temp, sizeof(temp), fp) != NULL) {
        if (strstr(temp, pat) != NULL) { // Using strstr() to check if pattern exists in line
            printf("%s", temp);
        }
    }

    fclose(fp);
    return 0;
}
