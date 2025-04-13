#include "Book.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Book::setBookDetails(string title, string author,
    string isbn, string date) {
    Title = title;
    Author = author;
    ISBN = isbn;
    DateAdd = date;
    Availability = true;
}

void Book::displayBookDetails() {
    cout << "\nBook Details:\n"
        << "Title: " << Title << endl
        << "Author: " << Author << endl
        << "ISBN: " << ISBN << endl
        << "Availability: " << (Availability ? "Available" : "Borrowed") << endl
        << "Date Added: " << DateAdd << "\n\n";
}

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

string Book::getISBN() { return ISBN; }
bool Book::isAvailable() { return Availability; }

bool Book::compareISBN(Book a, Book b) {
    return a.ISBN < b.ISBN;
}

void Book::sortBookData(Book books[], int size) {
    sort(books, books + size, compareISBN);
}