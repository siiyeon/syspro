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

    Book book;
    int mode;
    scanf("%d", &mode);

    while (fscanf(fp, "%d %s %s %d %d %d",
                  &book.id, book.title, book.author,
                  &book.year, &book.borrow_count, &book.available) == 6) {
        if (mode == 0)
            printf("%d %s %s %d %d %d\n",
                   book.id, book.title, book.author,
                   book.year, book.borrow_count, book.available);
        else if (mode == 1 && book.available == 1)
            printf("%d %s %s %d %d %d\n",
                   book.id, book.title, book.author,
                   book.year, book.borrow_count, book.available);
    }

    fclose(fp);
    return 0;
}

