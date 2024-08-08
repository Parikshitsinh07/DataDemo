#include <stdio.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of command line arguments is provided
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1; // Return an error code
    }

    // Open the source file for reading
    FILE *sourceFile = fopen(argv[1], "r");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return 1;
    }

    // Open the destination file for writing
    FILE *destinationFile = fopen(argv[2], "w");
    if (destinationFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile);
        return 1;
    }

    // Copy content from source to destination
    int ch;
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copied successfully!\n");

    return 0; // Return success
}

