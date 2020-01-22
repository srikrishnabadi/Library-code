#include <stdio.h>
#include <stdlib.h>

int* book; //This stores the total number of books in each shelf.

int** page;// This stores the total number of pages in each book of each shelf. The rows represent the shelves and the columns represent the books.

int main()
{
    int shelf;
    scanf("%d", &shelf);

    int query;
    scanf("%d", &query);

    book = (int*)malloc(sizeof(int)*shelf);
    page = (int**)malloc(sizeof(int*)*shelf);

    for(int i = 0; i < shelf; i++)
    {
        book[i] = 0;
        page[i] = (int*)malloc(sizeof(int));
    }

    while (query--)
    {
        int type_of_query;
        scanf("%d", &type_of_query);

        if (type_of_query == 1)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            book[x] += 1;
            page[x] = realloc(page[x], book[x]*sizeof(int));
            page[x][book[x] - 1] = y;

        }
        else if (type_of_query == 2)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", page[x][y]);
        }
        else
        {
            int x;
            scanf("%d", &x);
            printf("%d\n", book[x]);
        }
    }

    if (book)
        free(book);

    for (int i = 0; i < shelf; i++)
        if (page[i])
            free(page[i]);

    if (page)
        free(page);

    return 0;
}
/*
total_number_of_books[x] += 1;

            total_number_of_pages[x] = realloc(total_number_of_pages[x], total_number_of_books[x] * sizeof(int));
            total_number_of_pages[x][total_number_of_books[x]- 1] = y;*/
            /*
            int booksInShelf = *(total_number_of_books + x);
            *(total_number_of_pages+x)=(int*)realloc(*(total_number_of_pages+x),sizeof(int)*(booksInShelf+1));
            *(*(total_number_of_pages+x)+booksInShelf)=y;
            *(total_number_of_books + x) += 1;*/
            /*
            int shelf, pages;
        scanf("%d %d", &shelf, &pages);
        total_number_of_books[shelf]++;
        int *book = total_number_of_pages[shelf];
        while (*book != 0)
            book++;
        *book = pages;
        */
