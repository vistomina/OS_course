#include <stdio.h> 
#include <string.h> 
#include <sys/types.h> 
#include <unistd.h>
void main(void) {
    int n = 8;
    int pid;
        pid = fork();
    if (pid != 0){   //parent
        printf ("Hi from parent [%d - %d]\n", pid, n);
    } else if (pid == 0) { //child
        printf ("Hi from child [%d - %d]\n", pid, n);
    }
}
