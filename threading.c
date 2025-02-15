#include <stdio.h>
#include <pthread.h>
#include <unistd.h>  // For sleep()

void *print_message(void *arg) {
    int thread_num = *((int *)arg);
    printf("Hello from Thread %d (ID: %ld)\n", thread_num, pthread_self());
    return NULL;
}

int main() {
    pthread_t threads[3];
    int thread_ids[3] = {1, 2, 3};

    // Creating 3 threads
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, print_message, &thread_ids[i]);
    }

    // Waiting for all threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished execution.\n");
    return 0;
}
