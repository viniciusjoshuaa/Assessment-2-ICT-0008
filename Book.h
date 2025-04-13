#include <string>

class Book {
private:
    std::string Title, Author, ISBN, DateAdd;
    bool Availability;

public:
    void setBookDetails(std::string title, std::string author,
        std::string isbn, std::string date);
    void displayBookDetails();
    void borrowBook();
    void returnBook();
    std::string getISBN();
    bool isAvailable();
    static bool compareISBN(Book a, Book b);
    void sortBookData(Book books[], int size);
};

