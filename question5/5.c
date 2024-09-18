/*
===============================================================================
Name : 5.c
Author : Manas Ranjan Manna
Description : Write a program to print the system limitation of
 a. maximum length of the arguments to the exec family of functions.
 b. maximum number of simultaneous process per user id.
 c. number of clock ticks (jiffy) per second.
 d. maximum number of open files
 e. size of a page
 f. total number of pages in the physical memory
 g. number of currently available pages in the physical memory. 
Date: 18th Sept, 2024.
================================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main() {
    struct rlimit rlim;
    struct utsname uts;
    struct sysinfo info;

    // a. Maximum length of the arguments to the exec family of functions
    if (getrlimit(RLIMIT_AS, &rlim) == 0) {
        printf("Maximum length of the arguments to the exec family of functions: %ld bytes\n", rlim.rlim_max);
    } else {
        perror("getrlimit");
    }

    // b. Maximum number of simultaneous process per user id
    if (getrlimit(RLIMIT_NPROC, &rlim) == 0) {
        printf("Maximum number of simultaneous process per user id: %ld\n", rlim.rlim_max);
    } else {
        perror("getrlimit");
    }

    // c. Number of clock ticks (jiffy) per second
    if (uname(&uts) == 0) {
        printf("Number of clock ticks (jiffy) per second: %s\n", uts.sysname);
    } else {
        perror("uname");
    }

    // d. Maximum number of open files
    if (getrlimit(RLIMIT_NOFILE, &rlim) == 0) {
        printf("Maximum number of open files: %ld\n", rlim.rlim_max);
    } else {
        perror("getrlimit");
    }

    // e. Size of a page
    if (sysinfo(&info) == 0) {
        printf("Size of a page: %u bytes\n", info.mem_unit);
    } else {
        perror("sysinfo");
    }

    // f. Total number of pages in the physical memory
    if (sysinfo(&info) == 0) {
        printf("Total number of pages in the physical memory: %ld\n", info.totalram / info.mem_unit);
    } else {
        perror("sysinfo");
    }

    // g. Number of currently available pages in the physical memory
    if (sysinfo(&info) == 0) {
        printf("Number of currently available pages in the physical memory: %ld\n", info.freeram / info.mem_unit);
    } else {
        perror("sysinfo");
    }

    // h. Total physical memory
    if (sysinfo(&info) == 0) {
        printf("Total physical memory: %ld\n", info.totalram);
    } else {
        perror("sysinfo");
    }


    return 0;
}
