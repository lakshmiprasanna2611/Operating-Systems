#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_mutex_t mutex;
int shared_variable = 0;

void *thread_function(void *arg) {
    int thread_id = *((int *)arg);

    // Lock the mutex before accessing the shared variable
    pthread_mutex_lock(&mutex);

    // Critical section: Accessing and updating the shared variable
    printf("Thread %d is in critical section\n", thread_id);
    shared_variable++;
    printf("Thread %d updated the shared variable to: %d\n", thread_id, shared_variable);

    // Unlock the mutex after finishing the critical section
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize the mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        perror("Mutex initialization failed");
        exit(EXIT_FAILURE);
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Thread join failed");
            exit(EXIT_FAILURE);
        }
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}

/*output
Thread 1 is in critical section
Thread 1 updated the shared variable to: 1
Thread 4 is in critical section
Thread 4 updated the shared variable to: 2
Thread 2 is in critical section
Thread 2 updated the shared variable to: 3
Thread 3 is in critical section
Thread 3 updated the shared variable to: 4
Thread 5 is in critical section
Thread 5 updated the shared variable to: 5
*/