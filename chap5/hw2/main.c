#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 100

int main(int argc, char *argv[]) {
    FILE *fp;
    char lines[MAX_LINES][MAX_LEN];
    char buf[MAX_LEN];
    int lineCount = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror(argv[1]);
        exit(2);
    }

    while (fgets(buf, MAX_LEN, fp) != NULL) {
        buf[strcspn(buf, "\n")] = '\0'; 
		strcpy(lines[lineCount++], buf);
    }

    fclose(fp);

    for (int i = lineCount - 1; i >= 0; i--) {
        printf("%s\n", lines[i]);
    }

    return 0;
}

