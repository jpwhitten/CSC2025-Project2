#include <lib.h>      // provides _syscall and message
#include <unistd.h>   // provides function prototype (see step 1 below)

//The system call for printchildpids
int printchildpids(pid_t pid) {

    message m;      // Minix message to pass parameters to a system call
    
    m.m1_i1 = pid;  // set first integer of message to pid
    
    return _syscall(PM_PROC_NR, PRINTCPIDS, &m);  // invoke underlying system call
}