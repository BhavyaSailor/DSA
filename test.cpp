#include <iostream>
#include <string>
using namespace std;

// Struct to represent a Book in the library
struct Book {
    int id;            // Book ID
    string title;      // Book title
    string author;     // Author of the book
    float price;       // Price of the book
    Book* next;        // Pointer to the next book in the linked list
};

// Class to manage the Library
class Library {
private:
    Book* head = nullptr; // Pointer to the first book in the list (initially null)
public:
    void insertBook(string title, int id, string author, float price); // Function to insert a book
    void deleteBook(int id);   // Function to delete a book by ID
    void searchBook(int id);   // Function to search for a book by ID
    void displayBooks();       // Function to display all books
    void menu();               // Function to display the menu and handle user input
    void exit();               // Function to exit the library system
};



// Function to display the menu and handle user input
void Library::menu() {
    int choice;
    do {
        cout << "\nLibrary Management System Menu\n";
        cout << "1. Insert a Book\n";
        cout << "2. Delete a Book\n";
        cout << "3. Search for a Book\n";
        cout << "4. Display all Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Handle book insertion
                int id;
                string title;
                string author;
                float price;
                cout << "Enter Book ID: ";
                cin >> id;
                cout << "Enter Book Title: ";
                cin >> title;
                cout << "Enter Author's Name: ";
                cin >> author;
                cout << "Enter the Price: ";
                cin >> price;
                insertBook(title, id, author, price);
                break;
            }
            case 2: {
                // Handle book deletion
                int id;
                cout << "Enter Book ID to delete: ";
                cin >> id;
                deleteBook(id);
                break;
            }
            case 3: {
                // Handle book search
                int id;
                cout << "Enter Book ID to search: ";
                cin >> id;
                searchBook(id);
                break;
            }
            case 4:
                // Display all books
                displayBooks();
                break;
            case 5:
                // Exit the library system
                exit();
                break;
            default:
                // Handle invalid input
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
}


// Function to insert a new book into the library
void Library::insertBook(string title, int id, string author, float price) {
    // Check if the ID is already taken
    Book* current = head;
    while (current != nullptr) {
        if (current->id == id) {
            cout<<"-------------------------------------------------------\n";
            cout << "ID already taken. Please choose a different ID." << endl;
            cout<<"-------------------------------------------------------\n";
            return;
        }
        current = current->next;
    }
    
    // Create a new book and set its properties
    Book* newBook = new Book;
    newBook->id = id;
    newBook->title = title;
    newBook->author = author;
    newBook->price = price;
    newBook->next = nullptr; // New book will be the last node, so its next is nullptr

    // If the list is empty, make the new book the head
    if (head == nullptr) {
        head = newBook;
    } else {
        // Traverse to the end of the list
        current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        // Link the last node to the new book
        current->next = newBook;
    }
    cout<<"-------------------------------------------------------\n";
    cout << "Book inserted successfully." << endl;
    cout<<"-------------------------------------------------------\n";
}

// Function to delete a book from the library by ID
void Library::deleteBook(int id) {
    Book* current = head;
    Book* previous = nullptr;

    // Find the book to delete
    while (current != nullptr && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout<<"-------------------------------------------------------\n";
        cout << "Book not found." << endl;
        cout<<"-------------------------------------------------------\n";
        return;
    }

    // Remove the book from the list
    if (previous == nullptr) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    delete current; // Delete the book
    cout<<"-------------------------------------------------------\n";
    cout << "Book deleted successfully." << endl;
    cout<<"-------------------------------------------------------\n";
}


// Function to display all books in the library
void Library::displayBooks() {
    Book* current = head;

    while (current != nullptr) {
        cout<<"-------------------------------------------------------\n";
        cout << "Book ID: " << current->id << ", Title: " << current->title << ", Author: " << current->author << ", Price: " << current->price << endl;
        cout<<"-------------------------------------------------------\n";
        current = current->next;
    }
} 

// Function to search for a book by ID
void Library::searchBook(int id) {
    Book* current = head;

    while (current != nullptr) {
        if (current->id == id) {
            cout<<"-------------------------------------------------------\n";
            cout << "Book ID: " << current->id << ", Title: " << current->title << ", Author: " << current->author << ", Price: " << current->price << endl;
            cout<<"-------------------------------------------------------\n";
            return;
        }
        current = current->next;
    }

    cout << "Book not found." << endl;
}

// Function to exit the library system
void Library::exit() {
    cout<<"-------------------------------------------------------\n";
    cout <<"Exiting Library Management System. Thank you for visiting." << endl;
    cout<<"-------------------------------------------------------\n";
}

// Main function to start the library system
int main() {
    Library library;
    library.menu();
    return 0;
}