#include <lib.h>    // provides _syscall and message
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>

//Tests the printchildpids for part 1
int main(int argc, char **argv) {

    if (argc < 2)
        exit(1);    // expecting at least 1 integer parameter to test program
        
    int i = atoi(argv[1]); //Store input from command line

    printchildpids(i);  //print child pids
}