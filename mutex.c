#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

int account_balance = 0; // Shared resource
pthread_mutex_t lock; // Mutex to synchronize access

void* deposit(void* arg) {
    pthread_mutex_lock(&lock); // Lock the critical section
    int temp = account_balance;
    temp += 100;
    account_balance = temp;
    printf("Thread %ld added $100, Total Balance: $%d\n", (long)arg, account_balance);
    pthread_mutex_unlock(&lock); // Unlock the critical section
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    pthread_mutex_init(&lock, NULL); // Initialize the mutex

    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, deposit, (void*)i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock); // Destroy the mutex
    printf("Final Account Balance: $%d\n", account_balance);
    return 0;
}
