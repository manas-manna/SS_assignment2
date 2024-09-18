/*
===============================================================================
Name : 2.c
Author : Manas Ranjan Manna
Description : Write a program to print the system resource limits. Use getrlimit system call. 
Date: 18th Sept, 2024.
================================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit rlim;

    // Print the maximum size of the process's virtual memory
    if (getrlimit(RLIMIT_AS, &rlim) == 0) { 
        printf("Maximum virtual memory size: %ld bytes\n", rlim.rlim_max);
    } else { 
        perror("getrlimit"); 
    }

// Print the maximum file size in bytes
    if (getrlimit(RLIMIT_FSIZE, &rlim) == 0) {
        printf("Maximum File Size: %ld bytes\n", rlim.rlim_max);
    } else {
        perror("getrlimit");
    }
    
    // Print the maximum CPU time used by the process
    if (getrlimit(RLIMIT_CPU, &rlim) == 0) {
        printf("Maximum CPU time: %ld seconds\n", rlim.rlim_max);
    } else {
        perror("getrlimit");
    }

    // Print the maximum number of open files
    if (getrlimit(RLIMIT_NOFILE, &rlim) == 0) {
        printf("Maximum number of open files: %ld\n", rlim.rlim_max);
    } else {
        perror("getrlimit");
    }

    // Print the maximum number of child processes
    if (getrlimit(RLIMIT_NPROC, &rlim) == 0) {
        printf("Maximum number of child processes: %ld\n", rlim.rlim_max);
    } else {
        perror("getrlimit");
    }

    return 0;
}
