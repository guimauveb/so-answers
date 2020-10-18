#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Book {
    char *title;
    int cost;
} book;

int get_cost(struct Book **books, int cost, int size)
{
    int get_book_total = 0;

    for(int i = 0; i < size; i++) {
        printf("Book price: %d\n", books[i]->cost);
        if(books[i]->cost < cost) {
            printf("Book price is < 50$: %d\n", books[i]->cost);
            get_book_total++;
        }
    }
    return get_book_total;
}

struct Book *newBook(char *t, int c)
{
    struct Book *newBook = malloc(sizeof(struct Book));
    if (newBook == NULL) {
        free(newBook);
        return NULL;
    }

    newBook->title = (char*)malloc(strlen(t) * sizeof(char)); 
    strcpy(newBook->title, t);

    newBook->cost = c;

    return newBook;
}

void deleteBook(struct Book *book)
{
    free(book->title);
    free(book);
}

int main()
{
    // Used to generate random prices
    srand(time(NULL));
    // Array of 5 Book pointers
    struct Book *books[5];

    for (int i = 0; i < 5; i++) {
        // Generate a random price
        books[i] = newBook("title", rand());
    }

    int t = get_cost(books, 50, 5);
    printf("Number of books < 50$: %d\n", t);

    for (int i = 0; i < 5; i++) {
        deleteBook(books[i]);
    }

    return 0;
}

