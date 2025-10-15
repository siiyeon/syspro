#include <stdio.h>
#include <string.h>

#define MAXLINE 100 
#define MAXSTR 100

int main() {
    char lines[MAXSTR][MAXLINE]; 
	int count = 0;            
	char temp[MAXLINE]; 

	while (fgets(lines[count], MAXLINE, stdin) != NULL) {
		lines[count][strcspn(lines[count], "\n")] = '\0';
        count++;
    }

	for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strlen(lines[i]) < strlen(lines[j])) {
                strcpy(temp, lines[i]);
                strcpy(lines[i], lines[j]);
                strcpy(lines[j], temp);
            }
        }
    }

	for (int i = 0; i < count; i++) {
        printf("%s\n", lines[i]);
    }

    return 0;
}

