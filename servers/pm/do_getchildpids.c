#include <stdio.h>
#include "pm.h"         // provides global variables such as m_in
#include "mproc.h" 
#include "errno.h"	// provides errno

//definition for do_getchildpids
int do_getchildpids() {

	
	printf("Getting child pids\n");

    int nchildren = m_in.m1_i1; //set nchildren to first integer in message
    pid_t pid = m_in.m1_i2; //set nchildren to second integer in message
    pid_t *childpids = m_in.m1_p1; //set nchildren to first array in message

    int count = 0; //Set the count to 0
    pid_t parent;  //Declare a parent variable 

    //If the pid is invalid return -1 flag errno with invalid parameter
    if(pid < 1) {
    	errno = 22;
    	return -1;
    }

    //If nchildren is 0 return 0
    if(!nchildren) {
    	return count;
    }

    //If the nchildren is greater than NR_PROCS set it to NR_PROCS
    if(nchildren > NR_PROCS) {
    	nchildren = NR_PROCS;
    }


    pid_t matchingpids[nchildren]; //Array for storing matching pids

    //Loop through the process table checking for child processes
    for(int i = 0; i < NR_PROCS; i++) {

    	parent = mproc[mproc[i].mp_parent].mp_pid;

    	if(parent == pid && mproc[i].mp_pid != 0) { //If we find a child that isnt 0

    		matchingpids[count] = mproc[i].mp_pid; //Add to matching pid array
    		count++; //increment count

    		if(count == nchildren) { //if we reach the max pids that can be stored then break

    			break;
    		}
    	}
    }

    //copy the matchingpid array across processes to change the passed array of childpids
    int errval = sys_vircopy(SELF, matchingpids, who_e, childpids, sizeof(matchingpids));
    //if this fails set errno
    if(errval) {
    	errno = errval;
    	return - 1;
    }

    return count;
}
