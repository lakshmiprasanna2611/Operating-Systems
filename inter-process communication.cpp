#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ 27   // Size of shared memory segment

int main() {
    int shmid;
    key_t key;
    char *shm, *s;

    // Generate a unique key for shared memory
    if ((key = ftok(".", 'B')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Create a shared memory segment
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the process's address space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write a message to the shared memory
    strcpy(shm, "Hello, shared memory!");

    // Access the shared memory content
    s = shm;
    s += strlen(s);

    // Read from shared memory and print the message
    printf("Message read from shared memory: ");
    while (*s != '\0') {
        putchar(*s);
        s++;
    }
    putchar('\n');

    // Detach the shared memory segment from the process's address space
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Remove the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}
