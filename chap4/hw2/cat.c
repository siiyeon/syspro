#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 80

int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer[MAXLINE];
    int line;
    int print_line_number = 0;
    int start_index = 1;

	if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        print_line_number = 1;
        start_index = 2;
    }

    if (argc == start_index) {
        fp = stdin;
        line = 0;
        while (fgets(buffer, MAXLINE, fp) != NULL) {
            line++;
            if (print_line_number)
                printf("%3d  %s", line, buffer);
            else
                printf("%s", buffer);
        }
    } else {
        for (int i = start_index; i < argc; i++) {
            fp = fopen(argv[i], "r");
            if (fp == NULL) {
                fprintf(stderr, "Error: cannot open file %s\n", argv[i]);
                continue;
            }

            line = 0;
            while (fgets(buffer, MAXLINE, fp) != NULL) {
                line++;
                if (print_line_number)
                    printf("%3d  %s", line, buffer);
                else
                    printf("%s", buffer);
            }

            fclose(fp);
        }
    }

    return 0;
}
