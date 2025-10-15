#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 100

int main(int argc, char *argv[]) {
    FILE *fp;
    char savedText[MAX_LINES][MAX_LEN];
    char buf[MAX_LEN];
    char input[50];
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
        strcpy(savedText[lineCount++], buf);
    }
    fclose(fp);

    printf("file read success\n");
    printf("Total Line : %d\n", lineCount);
    printf("You can choose 1 ~ %d Line\n", lineCount);
    printf("Pls 'Enter' the line to select : ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 

    if (strcmp(input, "*") == 0) {
        for (int i = 0; i < lineCount; i++)
            printf("%d: %s\n", i + 1, savedText[i]);
    }

    else if (strchr(input, '-') != NULL) {
        int start, end;
        sscanf(input, "%d-%d", &start, &end);
        if (start < 1 || end > lineCount || start > end) {
            printf("Invalid range.\n");
            exit(3);
        }
        for (int i = start - 1; i < end; i++)
            printf("%d: %s\n", i + 1, savedText[i]);
    }

    else if (strchr(input, ',') != NULL) {
        char *token = strtok(input, ",");
        while (token != NULL) {
            int n = atoi(token);
            if (n >= 1 && n <= lineCount)
                printf("%d: %s\n", n, savedText[n - 1]);
            token = strtok(NULL, ",");
        }
    }

    else {
        int n = atoi(input);
        if (n >= 1 && n <= lineCount)
            printf("%d: %s\n", n, savedText[n - 1]);
        else
            printf("Invalid line number.\n");
    }

    return 0;
}

