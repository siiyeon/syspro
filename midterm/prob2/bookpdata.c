#include <stdio.h>

typedef struct {
    int id;
    char title[50];
    char author[50];
    int year;
    int borrow_count;
    int available;
} Book;

int main(void) {
    FILE *fp = fopen("db.dat", "r");
    if (fp == NULL) return 1;

    Book books[100];
    int count = 0;
    while (fscanf(fp, "%d %s %s %d %d %d",
                  &books[count].id, books[count].title,
                  books[count].author, &books[count].year,
                  &books[count].borrow_count, &books[count].available) == 6)
        count++;
    fclose(fp);

    int mode, id;
    scanf("%d", &mode);
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) return 1;

    if (mode == 0) {
        if (books[index].available == 1) {
            books[index].available = 0;
            books[index].borrow_count += 1;
        }
    } else if (mode == 1) {
        if (books[index].available == 0)
            books[index].available = 1;
    }

    fp = fopen("db.dat", "w");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %s %d %d %d\n",
                books[i].id, books[i].title, books[i].author,
                books[i].year, books[i].borrow_count, books[i].available);
    }
    fclose(fp);

    return 0;
}

