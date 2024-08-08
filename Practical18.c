#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll_No;
    char name[20];
    char department[20];
    char course[10];
};

void addRecord( struct Student student) {
	 FILE *file = fopen("students.txt", "a+");

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%d %s %s %s\n", student.roll_No, student.name, student.department, student.course);
    
     fclose(file);
}

void deleteRecord( int targetId) {
     FILE *file = fopen("students.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    rewind(file);
	FILE *tempFile = fopen("temp.txt", "w");

    if (tempFile == NULL) {
        perror("Error opening temporary file");
        exit(EXIT_FAILURE);
    }

    struct Student currentStudent;
    int recordDeleted = 0;

    while (fscanf(file, "%d %s %s %s", &currentStudent.roll_No, currentStudent.name, currentStudent.department, currentStudent.course) == 4) {
        if (currentStudent.roll_No != targetId) {
            fprintf(tempFile, "%d %s %s %s\n", currentStudent.roll_No, currentStudent.name, currentStudent.department, currentStudent.course);
        } else {
            recordDeleted = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (recordDeleted) {
        printf("Record Deleted!\n");
    } else {
        printf("Record not found!\n");
    }
}

void displayRecords() {
    FILE *file = fopen("students.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Check if the file is empty
    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0) {
        printf("No records found.\n");
        fclose(file);
        return;
    }

    // Rewind to the beginning of the file
    rewind(file);

    struct Student currentStudent;
    printf("\n%-10s %-20s %-20s %-10s\n", "Roll_No", "Name", "Department", "Course");

    while (fscanf(file, "%d %s %s %s", &currentStudent.roll_No, currentStudent.name, currentStudent.department, currentStudent.course) == 4) {
        printf("%-10d %-20s %-20s %-10s\n", currentStudent.roll_No, currentStudent.name, currentStudent.department, currentStudent.course);
    }

    fclose(file);
}


int main() {
   
    int option, targetId;
    struct Student newStudent;

    do {
        printf("\nSelect operation:\n");
        printf("1. Add Record\n");
        printf("2. Delete Record\n");
        printf("3. Display Records\n");
        printf("0. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Add Record
    				printf("Enter student Roll_No: ");
    				scanf("%d", &newStudent.roll_No);
    				printf("Enter student Name: ");
    				scanf("%s", newStudent.name);
    				printf("Enter student Department Name: ");
    				scanf("%19s", newStudent.department); // Limit the input to 19 characters
    				printf("Enter student Course Name: ");
    				scanf("%9s", newStudent.course);
                	addRecord(newStudent);
                	break;

            case 2:
                // Delete Record
                printf("Enter student Roll_No to delete: ");
                scanf("%d", &targetId);
                deleteRecord( targetId);
                break;

            case 3:
                // Display Records
                displayRecords();
                break;

            case 0:
                // Exit
                break;

            default:
                printf("Invalid option\n");
        }
    } while (option != 0);

   

    return 0;
}

