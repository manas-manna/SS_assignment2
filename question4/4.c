/*
===============================================================================
Name : 4.c
Author : Manas Ranjan Manna
Description : Write a program to measure how much time is taken to execute 100 getppid ( ) system call. Use time stamp counter. 
Date: 18th Sept, 2024.
================================================================================
*/
#include <stdio.h>
#include <stdint.h>  //for 64bit integers

uint64_t rdtsc() {
    uint64_t a, d;
    __asm__ volatile("rdtsc" : "=a"(a), "=d"(d)); //this assembly line means it executes 
//the rdtsc ,which loads the current tsc value into the a and d register.
//the volatile keyword ensures that thee ccompiler does not optimise this asssembly instruction
//can also write "__asm__ volatile("rdtsc" : "=a"(tsc)); ".then it will store in one 64 bit variable.thee above code was made for old computers when
//there were not much 64 bit register
//also __asm__ is a C extension that allows us to directly embed assembly code in our C program
    return (a | (d << 32)); //this line concating two 32bits  value to 64 bits
//means a is the right 32 bits and d is the left 32 bits and | is doing bitwise OR
}

//tsc is a 64 bit register that increments at a fixed frequence
int main() {
    uint64_t start, end;
    pid_t pid;

    start = rdtsc();

    for (int i = 0; i < 100; i++) {
        pid = getppid();
    }

    end = rdtsc();

    printf("Time taken for 100 getppid() calls: %f cycles\n", (double)(end - start));

    return 0;
}
