#include <iostream>
#include <vector>
#include <string>
#include <locale>  // Для работы с локалями

using namespace std;

// Класс для представления книги
class Book {
public:
    string author;   // Имя автора
    string title;    // Название книги
    string type;     // Тип книги: художественная или техническая

    // Конструктор с тремя параметрами
    Book(string bookAuthor, string bookTitle, string bookType)
        : author(bookAuthor), title(bookTitle), type(bookType) {}
};

// Класс для представления библиотеки
class Library {
public:
    vector<Book> books;  // Коллекция книг

    // Метод для добавления книги в библиотеку
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Метод для отображения всех книг в библиотеке
    void displayLibrary() {
        cout << "Содержимое библиотеки:" << endl;
        for (const auto& book : books) {
            cout << "Автор: " << book.author << ", Название: \"" << book.title << "\", Тип: " << book.type << endl;
        }
    }

    // Процедура для подсчета количества книг по типам
    void displayBookCount() {
        int fictionCount = 0;    // Художественная литература
        int technicalCount = 0;  // Техническая литература

        for (const auto& book : books) {
            switch (book.type[0]) {  // Проверяем первую букву типа книги
            case 'Х':            // Если первая буква 'Х', это художественная литература
                fictionCount++;
                break;
            case 'Т':            // Если первая буква 'Т', это техническая литература
                technicalCount++;
                break;
            }
        }

        cout << "Количество художественной литературы: " << fictionCount << endl;
        cout << "Количество технической литературы: " << technicalCount << endl;
    }
};

int main() {
    // Устанавливаем локаль для корректного отображения кириллицы
    setlocale(LC_ALL, "Russian");

    // Меняем кодировку консоли на 1251 (Windows-1251) для корректного отображения русского текста
    system("chcp 1251 > nul");

    // Создаем библиотеку
    Library library;

    // Добавляем книги в библиотеку
    library.addBook(Book("Лев Толстой", "Война и мир", "Художественная"));
    library.addBook(Book("Джордж Оруэлл", "1984", "Художественная"));
    library.addBook(Book("Бьёрн Страуструп", "Язык программирования C++", "Техническая"));
    library.addBook(Book("Джон Ресиг", "Секреты JavaScript", "Техническая"));

    // Отображаем содержимое библиотеки
    library.displayLibrary();

    // Подсчитываем и отображаем количество книг по типам
    library.displayBookCount();

    return 0;
}
