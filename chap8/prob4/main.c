#include <stdio.h>
#include <stdlib.h>

static void exit_handler1(void) { printf("first exit handler\n"); }
static void exit_handler2(void) { printf("second exit handler\n"); }

int main(void) {
    if (atexit(exit_handler1) != 0) perror("cannot register exit_handler1");
    if (atexit(exit_handler2) != 0) perror("cannot register exit_handler2");
    printf("end of main\n");
    exit(0);
}

