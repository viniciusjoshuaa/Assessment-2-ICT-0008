#pragma once
#include <string>

class Book {
private:
    std::string Title, Author, ISBN, DateAdd;
    bool Availability;

public:
    Book();
    Book(std::string title, std::string author, std::string isbn, std::string date);
    bool isValidISBN(const std::string& isbn);
    bool isValidDate(const std::string& date);
    bool setBookDetails(std::string title, std::string author, std::string isbn, std::string date);
    void displayBookDetails();
    bool isAvailable();

    // Getter functions for private members
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;
    std::string getDateAdd() const;

    static bool compareISBN(const Book& a, const Book& b);
    void borrowBook();
    void returnBook();

    // Sorting functions
    static void sortAscending(Book books[], int size);
    static void sortDescending(Book books[], int size);
    static void sortMixed(Book books[], int size);
};
