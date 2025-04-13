#include "Book.h"
#include <iostream>
using namespace std;

int main() {
    Book library[5];

    // Initialize with the books details
    library[0].setBookDetails("The Hobbit", "J.R.R. Tolkien",
        "20001", "01/01/2020");
    library[1].setBookDetails("The Silmarillion", "J.R.R. Tolkien",
        "20002", "02/02/2021");
    library[2].setBookDetails("The Children of Húrin", "J.R.R. Tolkien",
        "20003", "03/03/2022");
    library[3].setBookDetails("Unfinished Tales", "J.R.R. Tolkien",
        "20004", "04/04/2023");
    library[4].setBookDetails("The Fall of Gondolin", "J.R.R. Tolkien",
        "20005", "05/05/2024");

    // Sort books by ISBN
    library[0].sortBookData(library, 5);

    string inputISBN;
    int choice;

    while (true) {
        cout << "\nWelcome to the Community Library\n";
        cout << "1. Borrow a Book\n";
        cout << "2. Return a Book\n";
        cout << "3. Display All Books\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1: // Borrow
            cout << "Enter ISBN to borrow: ";
            cin >> inputISBN;
            for (int i = 0; i < 5; i++) {
                if (library[i].getISBN() == inputISBN) {
                    library[i].borrowBook();
                    break;
                }
                if (i == 4) cout << "Error: Book not found.\n";
            }
            break;

        case 2: // Return
            cout << "Enter ISBN to return: ";
            cin >> inputISBN;
            for (int i = 0; i < 5; i++) {
                if (library[i].getISBN() == inputISBN) {
                    library[i].returnBook();
                    break;
                }
                if (i == 4) cout << "Error: Book not found.\n";
            }
            break;

        case 3: // Display All
            cout << "\n--- Middle-earth Library Catalog ---\n";
            for (int i = 0; i < 5; i++) {
                library[i].displayBookDetails();
            }
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    cout << "Program exited. May the stars shine upon your path!\n";
    return 0;
}