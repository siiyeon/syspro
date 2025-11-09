#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

extern char **environ;

static void print_all_env(void) {
    for (char **p = environ; *p; ++p) puts(*p);
}
static void print_env_name(const char *name) {
    const char *v = getenv(name);
    puts(v ? v : "not set");
}
static void usage(const char *prog) {
    fprintf(stderr,
        "Usage: %s [options]\n"
        "  -e[NAME] : print env value (no NAME -> print all envs)\n"
        "  -u       : print real/effective user IDs\n"
        "  -g       : print real/effective group IDs\n"
        "  -i       : print process ID (PID)\n"
        "  -p       : print parent process ID (PPID)\n",
        prog);
}

int main(int argc, char *argv[]) {
    if (argc < 2) { usage(argv[0]); return 1; }

    for (int i = 1; i < argc; ++i) {
        const char *arg = argv[i];
        if (strncmp(arg, "-e", 2) == 0) {
            const char *name = NULL;
            if (strlen(arg) > 2) name = arg + 2;          // -eNAME
            else if (i + 1 < argc && argv[i+1][0] != '-') // -e NAME
                name = argv[++i];
            if (!name)  print_all_env();
            else        print_env_name(name);
        } else if (strcmp(arg, "-u") == 0) {
            printf("UID(real)=%d, UID(effective)=%d\n", (int)getuid(), (int)geteuid());
        } else if (strcmp(arg, "-g") == 0) {
            printf("GID(real)=%d, GID(effective)=%d\n", (int)getgid(), (int)getegid());
        } else if (strcmp(arg, "-i") == 0) {
            printf("PID=%d\n", (int)getpid());
        } else if (strcmp(arg, "-p") == 0) {
            printf("PPID=%d\n", (int)getppid());
        } else {
            fprintf(stderr, "Unknown option: %s\n", arg);
            usage(argv[0]); return 1;
        }
    }
    return 0;
}

