#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char c;
    FILE *fp1, *fp2;
    int mode = 0; 

    if (argc != 3 && argc != 4) {
        fprintf(stderr, "How to use: %s [option] source_file destination_file\n", argv[0]);
        return 1;
    }

    if (argc == 4) {
        mode = atoi(argv[1]);
        fp1 = fopen(argv[2], "r");
        fp2 = fopen(argv[3], "w");
    } else {
        fp1 = fopen(argv[1], "r");
        fp2 = fopen(argv[2], "w");
    }

    if (fp1 == NULL || fp2 == NULL) {
        perror("File open error");
        return 1;
    }

    while ((c = fgetc(fp1)) != EOF) {
        if (mode == 1)
            c = tolower(c);
        else if (mode == 2)
            c = toupper(c);
        fputc(c, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    if (argc == 4)
        fp2 = fopen(argv[3], "r");
    else
        fp2 = fopen(argv[2], "r");

    if (fp2 == NULL) {
        perror("File open error");
        return 1;
    }

    printf("결과 (destination 파일 내용): ");
    while ((c = fgetc(fp2)) != EOF)
        putchar(c);
    printf("\n");

    fclose(fp2);
    return 0;
}

