/*
============================================================================
Name : 1.b.c
Author : Manas Ranjan Manna
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
 a. ITIMER_REAL
 b. ITIMER_VIRTUAL
 c. ITIMER_PROF
Date: 18th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

void signal_handler(int sig) {
    printf("ITIMER_VIRTUAL alarm triggered!\n");
}

int main() {
    struct itimerval it;
//itimerval is used to store information about the interval timer
    
    signal(SIGALRM, signal_handler); //signal function is used to  join handler and SIGALRM
                                    //whenever SIGALRM signal is received the handler func will be called
    // Set the interval timer for 10 seconds
    it.it_interval.tv_sec = 10;
    it.it_interval.tv_usec = 0;
//it_interval is set to 10 sec and 0 microsec indicating that the timer should repeat every 10 sec
    it.it_value.tv_sec = 10;
    it.it_value.tv_usec = 0;
//it_value is set to 10 sec and 0 microsec indicating that the intial delay before the first alarm is 10 sec
    if (setitimer(ITIMER_PROF, &it, NULL) == -1) {  
//The setitimer function is used to set the interval timer for the ITIMER_VIRTUAL time domain. 
//The first argument specifies the time domain, the second argument is a pointer to the itimerval structure, 
//and the third argument is a pointer to a itimerval structure that can be used to retrieve the 
//remaining time until the next alarm (not used in this case)
        perror("setitimer");
        return 1;
    }

    // Wait for the alarm to trigger
    while (1) {
        sleep(1);
    }

    return 0;
}


/*Working
ITIMER_VIRTUAL is a time domain that measures CPU time consumed by a process,excluding the time spent in system calls..used for tracking the execution time of a process within its own context.
1.When the ITIMER_VIRTUAL timer expires, the SIGALRM signal is sent to the process.
2.The signal_handler function is then called to handle the signal.
3.The timer is set to repeat every 10 seconds, so the SIGALRM signal will be sent to the process every 10 seconds.
*/
