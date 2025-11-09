#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *v;
    v = getenv("HOME");  printf("HOME=%s\n",  v ? v : "(null)");
    v = getenv("SHELL"); printf("SHELL=%s\n", v ? v : "(null)");
    v = getenv("PATH");  printf("PATH=%s\n",  v ? v : "(null)");
    return 0;
}
