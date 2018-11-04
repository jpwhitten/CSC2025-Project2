#include <lib.h>    // provides _syscall and message
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>

//Tests the getnchildren for part 2
int main(int argc, char **argv) {

    if (argc < 2)
        exit(1);    // expecting at least 1 integer parameter to test program
        
    pid_t i = atoi(argv[1]); //store input from command line

    int result  = getnchildren(i); //store result from function

    printf("Count for pid: %d is %d\n", i, result); //print the result
}