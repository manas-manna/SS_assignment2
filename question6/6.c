/*
===============================================================================
Name : 6.c
Author : Manas Ranjan Manna
Description : Write a simple program to create three threads.
Date: 18th Sept, 2024.
================================================================================
*/
#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {   
    printf("Hello from thread %d\n", (int)arg);
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;  //these will store the thread id

    // Create three threads
    pthread_create(&thread1, NULL, thread_function, (void *)1);
//everytime a thread gets created it calls threadfucntion to inform us
    pthread_create(&thread2, NULL, thread_function, (void *)2);
    pthread_create(&thread3, NULL, thread_function, (void *)3);

    // Wait for all threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}
