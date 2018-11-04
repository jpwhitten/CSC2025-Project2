#include <stdio.h>
#include "pm.h"         // provides global variables such as m_in
#include "mproc.h" 
#include "errno.h"

//Definition for do_printchildpids function
int do_printchildpids() {

    pid_t pidsearch = m_in.m1_i1; //set pidsearch to be the first integer in the message

    //Handle an invalid pid being passed
    if(pidsearch < 1) {
	printf("Invalid pid\n");
        errno = 22;
    	return -1;
    }

    pid_t parent; //Declare a parent variable

    printf("Searching for chidren of process: %d\n", pidsearch); //Print what we are searching for

    //Loop through processes looking for matching parents
    for(int i = 0; i < NR_PROCS; i++) {

    	parent = mproc[mproc[i].mp_parent].mp_pid; //Get parent of process at i

    	if(parent == pidsearch && mproc[i].mp_pid != 0) { //If the process matches and isnt 0

    		printf("%d\n", mproc[i].mp_pid); //Print the childs pid

    	}
    }
    
    return 0;
}