#include <stdio.h> 
#include <string.h> 
#include <sys/types.h> 
#include <unistd.h>
int main() {
for (int i = 0; i < 3; i++){
    fork();
    sleep(5);
}
    return 0;
}
// before the first pstree command fork copies the process, then on the 2nd iteration 2 processes are copied again, and it happens on the 3rd 
iteration.
// 0 - - 0 - - 0 - - 0
//    |        |
//    |        0
//    |
//    |- 0 - - 0
//    |      
//    0
//if loop runs 5 times the algorithm will be almost the same but the whole scheme will be copied two more times such that there will be 32 processes
