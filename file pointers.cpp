#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 100
#define MAX_BLOCKS 1000

// Structure to represent a file
struct File {
    int index_block[MAX_BLOCKS]; // Index block containing pointers to data blocks
    int size; // Size of the file in blocks
};

// Function to initialize a file
void initializeFile(struct File *file, int size) {
    file->size = size;
    // Initialize index block pointers
    for (int i = 0; i < size; i++) {
        file->index_block[i] = i; // Each entry points to the corresponding block
    }
}

// Function to simulate file allocation strategy
void simulateFileAllocation(struct File files[], int num_files) {
    printf("File Allocation Strategy Simulation\n\n");

    // Print index block for each file
    for (int i = 0; i < num_files; i++) {
        printf("File %d: ", i + 1);
        for (int j = 0; j < files[i].size; j++) {
            printf("%d ", files[i].index_block[j]);
        }
        printf("\n");
    }
}

int main() {
    int num_files, file_size;

    printf("Enter the number of files: ");
    scanf("%d", &num_files);

    if (num_files > MAX_FILES) {
        printf("Exceeded maximum number of files allowed.\n");
        return 1;
    }

    struct File files[MAX_FILES];

    printf("Enter the size of each file (in blocks):\n");
    for (int i = 0; i < num_files; i++) {
        printf("Enter size of file %d: ", i + 1);
        scanf("%d", &file_size);
        if (file_size > MAX_BLOCKS) {
            printf("Exceeded maximum size of file allowed.\n");
            return 1;
        }
        initializeFile(&files[i], file_size);
    }

    simulateFileAllocation(files, num_files);

    return 0;
}

/*output
Enter the number of files: 1
Enter the size of each file (in blocks):
Enter size of file 1: 5
File Allocation Strategy Simulation

File 1: 0 1 2 3 4
*/