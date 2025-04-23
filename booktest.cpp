#include <iostream>
#include "Book.h"
#include <vector>
using namespace std;

void displayMenu() {
    cout << "\n==================================\n";
    cout << " Book Management System Menu\n";
    cout << "==================================\n";
    cout << " 1 : Add Book\n";
    cout << " 2 : Display Books\n";
    cout << " 3 : Borrow Book\n";
    cout << " 4 : Return Book\n";
    cout << " 5 : Delete Book\n";
    cout << " 6 : Sort Ascending\n";
    cout << " 7 : Sort Descending\n";
    cout << " 8 : Sort Mixed\n";
    cout << " 9 : Exit\n";
    cout << " Select an option: ";
}

int main() {
    vector<Book> books;
    bool result;
    string title, author, isbn, date;
    int choice;
    string isbnToFind;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(); // To ignore the newline character left by previous input

        switch (choice) {
        case 1: { // Add Book
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Book Author: ";
            getline(cin, author);
            cout << "Enter Book ISBN: ";
            getline(cin, isbn);
            cout << "Enter Book Date (dd/mm/yyyy): ";
            getline(cin, date);

            Book newBook;
            result = newBook.setBookDetails(title, author, isbn, date);
            if (result) {
                books.push_back(newBook);
                cout << "Book added successfully.\n";
            }
            else {
                cout << "Failed to add book. Invalid details.\n";
            }
            break;
        }
        case 2: { // Display Books
            cout << "\nList of Books:\n";
            for (auto& book : books) {
                book.displayBookDetails();
            }
            break;
        }
        case 3: { // Borrow Book
            cout << "Enter ISBN of book to borrow: ";
            getline(cin, isbnToFind);
            bool found = false;
            for (auto& book : books) {
                if (book.getISBN() == isbnToFind) {
                    book.borrowBook();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not found.\n";
            }
            break;
        }
        case 4: { // Return Book
            cout << "Enter ISBN of book to return: ";
            getline(cin, isbnToFind);
            bool found = false;
            for (auto& book : books) {
                if (book.getISBN() == isbnToFind) {
                    book.returnBook();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not found.\n";
            }
            break;
        }
        case 5: { // Delete Book
            cout << "Enter ISBN of book to delete: ";
            getline(cin, isbnToFind);
            auto it = books.begin();
            bool found = false;
            while (it != books.end()) {
                if (it->getISBN() == isbnToFind) {
                    books.erase(it);
                    cout << "Book deleted successfully.\n";
                    found = true;
                    break;
                }
                ++it;
            }
            if (!found) {
                cout << "Book not found.\n";
            }
            break;
        }
        case 6: { // Sort Ascending
            Book::sortAscending(books.data(), books.size());
            cout << "Books sorted in ascending order by title.\n";
            break;
        }
        case 7: { // Sort Descending
            Book::sortDescending(books.data(), books.size());
            cout << "Books sorted in descending order by title.\n";
            break;
        }
        case 8: { // Sort Mixed
            Book::sortMixed(books.data(), books.size());
            cout << "Books sorted in mixed order (Title Ascending, ISBN Ascending).\n";
            break;
        }
        case 9: { // Exit
            cout << "Exiting program.\n";
            return 0;
        }
        default:
            cout << "Invalid option. Please try again.\n";
        }
    }
}
