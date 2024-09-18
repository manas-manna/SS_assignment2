#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Hello from thread %d\n", (int)arg);
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;

    // Create three threads and store their IDs
    pthread_create(&thread1, NULL, thread_function, (void *)1);
    pthread_create(&thread2, NULL, thread_function, (void *)2);
    pthread_create(&thread3, NULL, thread_function, (void *)3);

    // Print the thread IDs
    printf("Thread 1 ID: %lu\n", thread1);
    printf("Thread 2 ID: %lu\n", thread2);
    printf("Thread 3 ID: %lu\n", thread3);

    // Wait for all threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}
