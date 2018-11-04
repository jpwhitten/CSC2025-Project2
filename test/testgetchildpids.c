#include <lib.h>    // provides _syscall and message
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>

//Tests the getchildpids function for part 3
int main(int argc, char **argv) {

    if (argc < 2)
        exit(1);    // expecting at least 1 integer parameter to test program
        
    pid_t pid = atoi(argv[1]);   //get the pid to test from the command line
    int nchildren = getnchildren(pid);   //set the size of the array to be the max amount of children for this pid
    pid_t childpids[nchildren];   //initilize the array to store the pids
    
    int result = getchildpids(nchildren, pid, childpids); //run and store result 
    
    printf("Children found: %d\n", result); //print how many childs found
    for(int i = 0; i < result; i++) {
        printf("%d\n", childpids[i]); //print all the child pids
    }  
}