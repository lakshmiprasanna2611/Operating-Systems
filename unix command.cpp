#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void lsSimulation(const char *directoryPath) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(directoryPath);

    if (dir == NULL) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    const char *directoryPath;

    if (argc < 2) {
        // No directory specified, list the current directory
        directoryPath = ".";
    } else {
        directoryPath = argv[1];
    }

    lsSimulation(directoryPath);

    return 0;
}

/*output
10.first fit.cpp
10.first fit.exe
11.organise file.cpp
11.organise file.exe
12.organise file 2level.cpp
12.organise file 2level.exe
13.file processing employee details.cpp
13.file processing employee details.exe
15.semaphores.cpp
15.semaphores.exe
16.FCFS out paging.cpp
16.FCFS out paging.exe
17.LRU.cpp
17.LRU.exe
18.optimal.cpp
18.optimal.exe
19.file allocation.cpp
19.file allocation.exe
20.index block.cpp
20.index block.exe
21.linked list.cpp
21.linked list.exe
9.Dinning philosophers.cpp
9.Dinning philosophers.exe
bankers algorithm.cpp
c scan.cpp
c scan.exe
copy content.cpp
copy content.exe
deadlock avoidance.cpp
deadlock avoidance.exe
dinning philosopher.cpp
dinning philosopher.exe
employee.dat
FCFS disk scheduling.cpp
FCFS disk scheduling.exe
FCFS.cpp
highest priority.cpp
join.cpp
join.exe
LRU.exe
multithreading.cpp
round robin.cpp
Scheduling.cpp
shared memory.cpp
system call.cpp
unix command.cpp
unix command.exe
Untitled7.cpp
Untitled7.exe
waiting process -high algorithm.cpp
*/