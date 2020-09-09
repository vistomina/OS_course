#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main() {
char command[100];
while (1){
    printf("Print your command: ");
    fgets(command, sizeof(command) / sizeof(char), stdin);
    if(strcmp (command, "exit\n") == 0){
            break;
    } else {
    system(command);
}
}
    return 0;
}
