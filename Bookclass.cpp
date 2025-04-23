#include "Book.h"
#include <iostream>
#include <cctype>
#include <regex>
#include <algorithm> // To use std::sort
using namespace std;

Book::Book() {
    Title = Author = ISBN = DateAdd = "";
    Availability = true;
}

Book::Book(string title, string author, string isbn, string date) {
    setBookDetails(title, author, isbn, date);
}

bool Book::isValidISBN(const string& isbn) {
    return all_of(isbn.begin(), isbn.end(), ::isdigit);
}

bool Book::isValidDate(const string& date) {
    regex pattern("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\\d{4}$");
    return regex_match(date, pattern);
}

bool Book::setBookDetails(string title, string author, string isbn, string date) {
    if (!isValidISBN(isbn)) {
        cout << "Invalid ISBN. It must be numeric." << endl;
        return false;
    }
    if (!isValidDate(date)) {
        cout << "Invalid date. Use dd/mm/yyyy format." << endl;
        return false;
    }
    Title = title;
    Author = author;
    ISBN = isbn;
    DateAdd = date;
    Availability = true;
    return true;
}

void Book::displayBookDetails() {
    cout << "\nBook Details:\n"
        << "Title: " << Title << endl
        << "Author: " << Author << endl
        << "ISBN: " << ISBN << endl
        << "Availability: " << (Availability ? "Available" : "Borrowed") << endl
        << "Date Added: " << DateAdd << "\n";
}

bool Book::isAvailable() {
    return Availability;
}

string Book::getTitle() const { return Title; }
string Book::getAuthor() const { return Author; }
string Book::getISBN() const { return ISBN; }
string Book::getDateAdd() const { return DateAdd; }

void Book::borrowBook() {
    if (Availability) {
        Availability = false;
        cout << "Book borrowed successfully!\n";
    }
    else {
        cout << "Error: Book is already borrowed.\n";
    }
}

void Book::returnBook() {
    if (!Availability) {
        Availability = true;
        cout << "Book returned successfully!\n";
    }
    else {
        cout << "Error: Book was not borrowed.\n";
    }
}

// Sort books in ascending order by Title
void Book::sortAscending(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.getTitle() < b.getTitle(); // Sort by Title in ascending order
        });
}

// Sort books in descending order by Title
void Book::sortDescending(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.getTitle() > b.getTitle(); // Sort by Title in descending order
        });
}

// Sort books in mixed order: First by Title in ascending order, then by ISBN in ascending order
void Book::sortMixed(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        if (a.getTitle() == b.getTitle()) {
            return a.getISBN() < b.getISBN();  // If Titles are the same, sort by ISBN
        }
        return a.getTitle() < b.getTitle();  // Otherwise, sort by Title in ascending order
        });
}
