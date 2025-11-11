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
    Book books[4] = {
        {1, "1984", "George", 1949, 7, 0},
        {2, "Luster", "Raven", 2020, 3, 1},
        {3, "Hamnet", "Maggie", 2020, 0, 0},
        {4, "theWish", "Nocholas", 2021, 2, 1}
    };

    FILE *fp = fopen("db.dat", "w");
    if (fp == NULL) return 1;

    for (int i = 0; i < 4; i++) {
        fprintf(fp, "%d %s %s %d %d %d\n",
                books[i].id, books[i].title, books[i].author,
                books[i].year, books[i].borrow_count, books[i].available);
    }

    fclose(fp);
    return 0;
}

