#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
    private:
        string title;
        string author;
        string isbn;

    public:
        Book(string t, string a, string i) : title(t), author(a), isbn(i) {}
        string getTitle() const { return title; }
        string getAuthor() const { return author; }
        string getIsbn() const { return isbn; }
};

class Catalog {
private:
    vector<Book> books;
public:
    void addBook(const Book& book) { books.push_back(book); };
    bool removeBook(const string& isbn) {
        for (auto it = books.begin(); it != books.end(); it++) {
            if (it->getIsbn() == isbn) {
                books.erase(it);
                return true;
            }
        }
        return false;
    };
    bool isEmpty() const { return books.empty(); }
    void displayBooks() {
        for (const auto& book : books) {
            cout << "Titlu: " << book.getTitle() << ", Author: " << book.getAuthor() << " , ISBN: " << book.getIsbn() << endl;
        }
    }
};

int main() {
    Catalog catalog;

    string sa;
    cout << "Welcome! Do you want to see the book list or do you want to add a new book to the list?" << endl;
    cout << "s - see\na - add" << endl;
    cin >> sa;

    if (sa == "s") {
        if (catalog.isEmpty()) {
            cout << "The catalog is currently empty." << endl;
        } else {
            cout << "Books in catalog:" << endl;
            catalog.displayBooks();
        }
    } else if (sa == "a") {
        string title, author, isbn;
        cout << "Enter title: ";
        cin.ignore(); 
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);
        cout << "Enter ISBN: ";
        getline(cin, isbn);

        Book newBook(title, author, isbn);
        catalog.addBook(newBook);

        cout << "'" << title << "' added successfully." << endl;
        cout << "\nUpdated books in catalog:" << endl;
        catalog.displayBooks();
    } else {
        cout << "Invalid input." << endl;
    }

    string yn;
    cout << "\nDo you want to remove any book?" << endl;
    cout << "Type: \ny - yes\nn - no" << endl;
    cin >> yn;

    if (yn == "y") {
        string isbnToRemove;
        cout << "\nEnter the ISBN of the book to remove: ";
        cin >> isbnToRemove;

        cout << "\nRemoving '"<< isbnToRemove <<"'..." << endl;
        if (catalog.removeBook(isbnToRemove)) {
            cout << "'" << isbnToRemove << "' removed successfully." << endl;
        } else {
            cout << "Book not found." << endl;
        }

        cout << "\nBooks in catalog after removal:" << endl;
        catalog.displayBooks();
    } else {
        cout << "No book will be removed.\nHave a nice day!" << endl;
    }
    
    return 0;
};