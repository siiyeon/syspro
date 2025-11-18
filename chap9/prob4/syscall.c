#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int mysystem(const char *cmdstring) {
    int pid, status;
    if (cmdstring == NULL)
        return 1;

    pid = fork();
    if (pid < 0)
        return -1;
    else if (pid == 0) {
        execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
        _exit(127);
    }

    do {
        if (waitpid(pid, &status, 0) == -1) {
            if (errno != EINTR)
                return -1;
        } else
            return status;
    } while (1);
}

int main() {
    int status;

    status = system("date");
    printf("end code %d\n", WEXITSTATUS(status));

    status = system("hello");
    printf("end code %d\n", WEXITSTATUS(status));

    status = system("who; exit 44");
    printf("end code %d\n", WEXITSTATUS(status));

    return 0;
}

