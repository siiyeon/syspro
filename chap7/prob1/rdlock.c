#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[]) {
    int fd, id;
    struct student record;
    struct flock lock;

    if (argc < 2) {
        fprintf(stderr, "How to use : %s file\n", argv[0]);
        exit(1);
    }
    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    printf("\nEnter StudentID to search : ");
    while (scanf("%d", &id) == 1) {
        lock.l_type   = F_RDLCK;               
		lock.l_whence = SEEK_SET;
        lock.l_start  = (off_t)(id - START_ID) * sizeof(record);
        lock.l_len    = (off_t)sizeof(record);
        if (fcntl(fd, F_SETLKW, &lock) == -1) {          
			perror("fcntl F_RDLCK");
            exit(3);
        }

        lseek(fd, (off_t)(id - START_ID) * sizeof(record), SEEK_SET);
        if (read(fd, &record, sizeof(record)) > 0 && record.id != 0)
            printf("Name:%s\tStuID:%d\tScore:%d\n", record.name, record.id, record.score);
        else
            printf("No record %d\n", id);

        lock.l_type = F_UNLCK;                    
		fcntl(fd, F_SETLK, &lock);

        printf("\nEnter StudentID to search : ");
    }
    close(fd);
    return 0;
}

