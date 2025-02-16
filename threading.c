#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3

void* print_message(void* thread_id) {
    long tid = (long)thread_id;
    printf("Thread %ld is running\n", tid);
    sleep(1); // Simulate work
    printf("Thread %ld has finished execution\n", tid);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, print_message, (void*)i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed execution.\n");
    return 0;
}
