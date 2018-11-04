#include <lib.h>      // provides _syscall and message
#include <unistd.h>   // provides function prototype (see step 1 below)

//The system call for getchildpids
int getchildpids(pid_t pid, int nchildren, pid_t *childpids) {

    message m;      // Minix message to pass parameters to a system call
    
    m.m1_i1 = pid;  // set first integer of message to pid
    m.m1_i2 = nchildren; // set second integer of message to nchildren
    m.m1_p1 = childpids; // set first array of message to childpids
    
    return _syscall(PM_PROC_NR, GETCHILDPID, &m);  // invoke underlying system call
}