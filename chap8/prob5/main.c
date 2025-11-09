#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("my process id: [%d]\n", getpid());
    printf("my parent process id: [%d]\n", getppid());
    return 0;
}

