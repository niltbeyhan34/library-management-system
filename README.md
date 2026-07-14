# 📚 Library Management System (C)

A simple **Library Management System** developed in **C programming language**. This project allows users to manage a library by adding, viewing, searching, updating, deleting, and saving book information.

## Features

*  Add a new book
*  View all books
*  Search books by ID
*  Search books by title (case-insensitive)
*  Update book information
*  Delete books by ID or title
*  Save book data to a text file
*  Automatically load saved books when the program starts
*  Prevent duplicate book IDs

## Technologies Used

* C Programming Language
* Standard C Libraries

  * `stdio.h`
  * `string.h`
  * `ctype.h`

## File Structure

```text
Library-Management-System/
│── main.c
│── books.txt
└── README.md
```

## How to Run

1. Clone the repository:

```bash
git clone https://github.com/niltbeyhan34/library-management-system.git
```

2. Compile the program:

```bash
gcc main.c -o library
```

3. Run the program:

```bash
./library
```

## Sample Output

```text
===== LIBRARY MANAGEMENT =====

1. Add Book
2. View Books
3. Search Book
4. Delete Book
5. Update Book
6. Save Book List to File
7. Exit
```

## Project Description

This project was developed to practice fundamental C programming concepts such as:

* Structures (`struct`)
* Arrays
* Functions
* File Handling
* String Manipulation
* Searching and Updating Records

The application stores book information in a text file, allowing the data to persist even after the program is closed.

## Author

**Nil Tuana Beyhan**
