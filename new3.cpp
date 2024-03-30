#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title(title), author(author), isbn(isbn) {}

    std::string getISBN() const {
        return isbn;
    }

    void displayDetails() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

class Library {
private:
    static const int MAX_BOOKS = 100;
    Book* books[MAX_BOOKS];
    int numBooks;

public:
    Library() : numBooks(0) {}

    void addBook(Book* book) {
        if (numBooks < MAX_BOOKS) {
            books[numBooks++] = book;
        } else {
            std::cerr << "Library is full. Cannot add more books." << std::endl;
        }
    }

    void findBook(const std::string& isbn) const {
        bool found = false;
        for (int i = 0; i < numBooks; ++i) {
            if (books[i]->getISBN() == isbn) {
                books[i]->displayDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "Book with ISBN " << isbn << " not found in the library." << std::endl;
        }
    }
};

int main() {
    Library library;

    
    Book book1("c++", "Ft", "565");
    Book book2("java", "Hr", "084");
    Book book3("html", "Ge", "35");

    library.addBook(&book1);
    library.addBook(&book2);
    library.addBook(&book3);

    
    std::string isbn;
    std::cout << "Enter ISBN to search for a book: ";
    std::cin >> isbn;

    library.findBook(isbn);

    return 0;
}

