#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
int counter = 0;

void *increment_counter(void *arg) {
    pthread_mutex_lock(&lock);
    counter++;
    printf("Counter Value: %d (Thread ID: %ld)\n", counter, pthread_self());
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[5];

    pthread_mutex_init(&lock, NULL);

    // Create 5 threads
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, increment_counter, NULL);
    }

    // Join threads
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    printf("Final Counter Value: %d\n", counter);
    return 0;
}
