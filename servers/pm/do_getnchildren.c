#include <stdio.h>
#include "pm.h"         // provides global variables such as m_in
#include "mproc.h" 
#include "errno.h"

//Definition for do_getnchildren
int do_getnchildren() {

    pid_t pidsearch = m_in.m1_i1; //set pidsearch to be the first integer in the message

    //Handle an invalid pid being passed
    if(pidsearch < 1) {
	printf("Invalid pid\n");
	errno = 22;
    	return -1;
    }

    int count = 0; //Set count to 0
    pid_t parent; //Declare a parent variable

    //Loop through the process table looking for matching parents
    for(int i = 0; i < NR_PROCS; i++) {

    	parent = mproc[mproc[i].mp_parent].mp_pid; //get parent of process at i

    	if(parent == pidsearch && mproc[i].mp_pid != 0) { //Is it a child of pidsearch that isnt 0

    		count++; //If so then increment count

    	}
    }

    return count;
}
