#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    for (size_t i = 0; i < 10; i++)
    {
        memset(malloc(100 * 1024 * 1024), '0', 100 * 1024 * 1024);
        sleep(1);
    }

    return 0;
}

//My PC has not much memory, so OS gave swaps to fill in memory
