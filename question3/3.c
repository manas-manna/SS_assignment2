/*
===============================================================================
Name : 3.c
Author : Manas Ranjan Manna
Description : Write a program to set (any one) system resource limit. Use setrlimit system call. 
Date: 18th Sept, 2024.
================================================================================
*/
#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit rlim;

//using number of open files to do this 
    // Get the current limits
    if (getrlimit(RLIMIT_NOFILE, &rlim) == -1) {
        perror("getrlimit");
        return 1;
    }

    // Setting the soft limit 
    rlim.rlim_cur = 100;
//soft limit means current limit and hard limit means max allowed limit
    // Setting the hard limit
    rlim.rlim_max = 200;

    // Apply the new limits
    if (setrlimit(RLIMIT_NOFILE, &rlim) == -1) {
        perror("setrlimit");
        return 1;
    }

    printf("New limits:\n");
    printf("  Soft limit: %ld\n", rlim.rlim_cur);
    printf("  Hard limit: %ld\n", rlim.rlim_max);

    return 0;
}
