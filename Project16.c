#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_BLOCKS 100

typedef struct {
    int start;
    int size;
    int allocated;
} Block;

Block memory[MAX_BLOCKS];

void initializeMemory(int totalSize) {
    memory[0].start = 0;
    memory[0].size = totalSize;
    memory[0].allocated = 0;
}

void displayMemory() {
    printf("\nMemory Layout:\n");
    printf("Start\tSize\tStatus\n");
    int i;
    for ( i = 0; i < MAX_BLOCKS; i++) {
        if (memory[i].size > 0) {
            printf("%d\t%d(byte)\t", memory[i].start, memory[i].size);
            if (memory[i].allocated) {
                printf("Allocated\n");
            } else {
                printf("Free\n");
            }
        }
    }
}

int bestFitAllocate(int processSize) {
    int bestFitIndex = -1;
    int minSize = INT_MAX;
    int i;
    for (i = 0; i < MAX_BLOCKS; i++) {
        if (!memory[i].allocated && memory[i].size >= processSize && memory[i].size < minSize) {
            bestFitIndex = i;
            minSize = memory[i].size;
        }
    }

    if (bestFitIndex != -1) {
        memory[bestFitIndex].allocated = 1;
        return bestFitIndex;
    } else {
        return -1;
    }
}

void deallocate(int blockIndex) {
    if (blockIndex >= 0 && blockIndex < MAX_BLOCKS) {
        memory[blockIndex].allocated = 0;
    }
}

int main() {
    int totalSize, choice, processSize, allocatedBlockIndex;

    printf("Enter the total size(byte) of memory: ");
    scanf("%d", &totalSize);

    initializeMemory(totalSize);

    do {
        printf("\nMenu:\n");
        printf("1. Allocate\n");
        printf("2. Deallocate\n");
        printf("3. Display Memory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the size (byte) of the process to allocate: ");
                scanf("%d", &processSize);

                allocatedBlockIndex = bestFitAllocate(processSize);

                if (allocatedBlockIndex != -1) {
                    printf("Process allocated at block %d .\n", allocatedBlockIndex);
                } else {
                    printf("No suitable block found for allocation.\n");
                }
                break;

            case 2:
                printf("Enter the block index to deallocate: ");
                scanf("%d", &allocatedBlockIndex);

                deallocate(allocatedBlockIndex);
                printf("Block deallocated successfully.\n");
                break;

            case 3:
                displayMemory();
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}

