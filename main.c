#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
};

struct Book books[MAX_BOOKS];
int bookCount = 0;

void addBook();
void saveToFile();
void loadFromFile();
void viewBooks();
void searchBook();
void deleteBook();
void updateBook();
void toLowerCase(char str[]) {

    for(int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }

}

int main() {

    int choice;
    loadFromFile();

    do {

        printf("\n===== LIBRARY MANAGEMENT =====\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Update Books\n");
        printf("6. Save Book List to File\n");
        printf("7. Exit\n");

        printf("Choose: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                addBook();
                break;

            case 2:
                viewBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                deleteBook();
                break;

            case 5:
                updateBook();
                break;

            case 6:
                saveToFile();
                printf("\nBook list saved successfully!\n");
                break;

            case 7:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    }while(choice!=7);

    return 0;
}
void addBook(){

    if(bookCount == MAX_BOOKS){
    printf("\nLibrary is full!\n");
    return;
    }

    printf("\n--- Add Book ---\n");

    printf("Enter Book ID: ");
    scanf("%d", &books[bookCount].id);

    for (int i = 0; i < bookCount; i++) {

        if (books[i].id == books[bookCount].id) {
            printf("\nThis ID already exists!\n");
            return;
        }
    }   

    getchar();

    printf("Enter Book Title: ");
    fgets(books[bookCount].title, sizeof(books[bookCount].title), stdin);
    books[bookCount].title[strcspn(books[bookCount].title, "\n")] = '\0';

    printf("Enter Author Name: ");
    fgets(books[bookCount].author, sizeof(books[bookCount].author), stdin);
    books[bookCount].author[strcspn(books[bookCount].author, "\n")] = '\0';

    bookCount++;
    saveToFile();

    printf("\nBook added successfully!\n");

}

void viewBooks(){

    if (bookCount == 0) {
        printf("\nNo books found!\n");
        return;
    }

    printf("\n===== BOOK LIST =====\n");

    for (int i = 0; i < bookCount; i++) {

        printf("\nBook %d\n", i + 1);
        printf("ID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);

    }
}

void searchBook() {

    int choice;

    printf("\n===== SEARCH BOOK =====\n");
    printf("1. Search by ID\n");
    printf("2. Search by Title\n");
    printf("Choose: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1: {

        int id;
        int found = 0;

        printf("\nEnter Book ID: ");
        scanf("%d", &id);

        for(int i = 0; i < bookCount; i++) {

            if(books[i].id == id) {

                printf("\nBook Found!\n");
                printf("ID: %d\n", books[i].id);
                printf("Title: %s\n", books[i].title);
                printf("Author: %s\n", books[i].author);

                found = 1;
                break;
            }
        }

     if(!found)
     printf("\nBook not found!\n");
            break;
        }

        case 2: {

            char title[100];
            int found = 0;

            getchar(); 

            printf("\nEnter Book Title: ");
            fgets(title, sizeof(title), stdin);

            title[strcspn(title, "\n")] = '\0';

            char searchTitle[100];
            strcpy(searchTitle, title);
            toLowerCase(searchTitle);

            for(int i = 0; i < bookCount; i++) {

                char bookTitle[100];
                strcpy(bookTitle, books[i].title);
                toLowerCase(bookTitle);

                if(strcmp(bookTitle, searchTitle) == 0) {

                    printf("\nBook Found!\n");
                    printf("ID: %d\n", books[i].id);
                    printf("Title: %s\n", books[i].title);
                    printf("Author: %s\n", books[i].author);

                    found = 1;
                    break;
                }
            }

            if(!found)
                printf("\nBook not found!\n");

            break;
        }

        default:
            printf("\nInvalid choice!\n");
    }
}

void deleteBook(){

    if(bookCount == 0){
    printf("\nNo books to delete!\n");
    return;
    }

    int choice;

    printf("\n===== DELETE BOOK =====\n");
    printf("1. Delete by ID\n");
    printf("2. Delete by Title\n");
    printf("Choose: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1: {

            int id;
            int found = 0;

            printf("\nEnter Book ID: ");
            scanf("%d", &id);

            for(int i = 0; i < bookCount; i++) {

                if(books[i].id == id) {

                    for(int j = i; j < bookCount - 1; j++) {
                        books[j] = books[j + 1];
                    }

                    bookCount--;
                    saveToFile();
                    found = 1;
                    printf("\nBook deleted successfully!\n");
                    break;
                }
            }

            if(!found)
                printf("\nBook not found!\n");

            break;
        }

        case 2: {

            char title[100];
            int found = 0;

            getchar(); 

            printf("\nEnter Book Title: ");
            fgets(title, sizeof(title), stdin);

            title[strcspn(title, "\n")] = '\0';

            char searchTitle[100];
            strcpy(searchTitle, title);
            toLowerCase(searchTitle);

            for(int i = 0; i < bookCount; i++) {

                char bookTitle[100];
                strcpy(bookTitle, books[i].title);
                toLowerCase(bookTitle);

                if(strcmp(bookTitle, searchTitle) == 0) {

                    for(int j = i; j < bookCount - 1; j++) {
                        books[j] = books[j + 1];
                    }

                    bookCount--;
                    saveToFile();
                    found = 1;
                    printf("\nBook deleted successfully!\n");
                    break;
                }
            }

            if(!found)
                printf("\nBook not found!\n");

            break;
        }

        default:
            printf("\nInvalid choice!\n");
    }
}

void updateBook(){

    if(bookCount == 0){
        printf("\nNo books found!\n");
        return;
    }

    int id;
    int found = 0;

    printf("\nEnter Book ID: ");
    scanf("%d", &id);

    for(int i = 0; i < bookCount; i++){

        if(books[i].id == id){

            found = 1;

            printf("\n===== UPDATE BOOK =====\n");
            printf("1. Change Title\n");
            printf("2. Change Author\n");
            printf("3. Change Both\n");

            int choice;

            printf("Choose: ");
            scanf("%d", &choice);
            getchar(); 

            switch(choice){

                case 1:

                    printf("\nEnter New Title: ");
                    fgets(books[i].title, sizeof(books[i].title), stdin);
                    books[i].title[strcspn(books[i].title, "\n")] = '\0';

                    printf("\nTitle updated successfully!\n");
                    saveToFile();
                    break;

                case 2:

                    printf("\nEnter New Author: ");
                    fgets(books[i].author, sizeof(books[i].author), stdin);
                    books[i].author[strcspn(books[i].author, "\n")] = '\0';

                    printf("\nAuthor updated successfully!\n");
                    saveToFile();
                    break;

                case 3:

                    printf("\nEnter New Title: ");
                    fgets(books[i].title, sizeof(books[i].title), stdin);
                    books[i].title[strcspn(books[i].title, "\n")] = '\0';

                    printf("Enter New Author: ");
                    fgets(books[i].author, sizeof(books[i].author), stdin);
                    books[i].author[strcspn(books[i].author, "\n")] = '\0';

                    printf("\nBook updated successfully!\n");
                    saveToFile();
                    break;

                default:
                    printf("\nInvalid choice!\n");
            }
            break;
        }
    }

    if(!found){
        printf("\nBook not found!\n");
    }

}

void saveToFile() {

    FILE *file = fopen("books.txt", "w");

    if(file == NULL){
        printf("File could not be opened!\n");
        return;
    }

    fprintf(file, "=========================================\n");
    fprintf(file, "      LIBRARY MANAGEMENT SYSTEM\n");
    fprintf(file, "=========================================\n\n");
    fprintf(file, "Total Books : %d\n\n", bookCount);

    for(int i = 0; i < bookCount; i++){

        fprintf(file, "=========================================\n");
        fprintf(file, "Book %d Information\n", i + 1);
        fprintf(file, "ID     : %d\n", books[i].id);
        fprintf(file, "Title  : %s\n", books[i].title);
        fprintf(file, "Author : %s\n", books[i].author);
        fprintf(file, "=========================================\n\n");

    }

    fclose(file);
}

void loadFromFile() {

    FILE *file = fopen("books.txt", "r");

    if(file == NULL){
        return;
    }

    char line[200];

    while(fgets(line, sizeof(line), file) != NULL){

        if(strncmp(line, "Book", 4) == 0){

            fscanf(file, "ID     : %d\n", &books[bookCount].id);

            fgets(line, sizeof(line), file);
            sscanf(line, "Title  : %[^\n]", books[bookCount].title);

            fgets(line, sizeof(line), file);
            sscanf(line, "Author : %[^\n]", books[bookCount].author);

            /* Ayırıcı çizgileri oku */
            fgets(line, sizeof(line), file);
            fgets(line, sizeof(line), file);

            bookCount++;

            if(bookCount >= MAX_BOOKS)
                break;
        }
    }

    fclose(file);
}