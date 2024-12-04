#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

// Класс для представления книги
class Book {
private:
    string author;   // Имя автора
    string title;    // Название книги
    string type;     // Тип книги: художественная или техническая

public:
    // Пользовательский конструктор с тремя параметрами
    Book(string bookAuthor, string bookTitle, string bookType) {
        if (bookAuthor.empty() || bookTitle.empty()) {
            throw invalid_argument("Автор и название книги не должны быть пустыми!");
        }
        author = bookAuthor;
        title = bookTitle;
        type = bookType;
    }

    // Метод для отображения информации о книге
    void displayBook() const {
        cout << "Автор: " << author << ", Название: \"" << title << "\", Тип: " << type << endl;
    }
};

// Класс для представления библиотеки
class Library {
private:
    vector<Book> books;  // Коллекция книг

public:
    // Метод для добавления книги в библиотеку
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Метод для отображения всех книг в библиотеке
    void displayLibrary() const {
        if (books.empty()) {
            cout << "Библиотека пуста!" << endl;
        }
        else {
            cout << "Содержимое библиотеки:" << endl;
            for (const auto& book : books) {
                book.displayBook();
            }
        }
    }
};

int main() {
    system("chcp 1251 > nul");
    try {
        // Создание объекта библиотеки
        Library library;

        // Добавление книг в библиотеку
        library.addBook(Book("Лев Толстой", "Война и мир", "Художественная"));
        library.addBook(Book("Джордж Оруэлл", "1984", "Художественная"));
        library.addBook(Book("Бьёрн Страуструп", "Язык программирования C++", "Техническая"));
        library.addBook(Book("Джон Ресиг", "Секреты JavaScript", "Техническая"));

        // Отображение содержимого библиотеки
        library.displayLibrary();
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
