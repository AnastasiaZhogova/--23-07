#include <iostream>
#include <string>

using namespace std;

// Базовый класс Publication
class Publication {
protected:
    string title;  // Название книги
    float price;   // Цена книги

public:
    // Виртуальный метод для ввода данных
    virtual void getdata() {
        cout << "Введите название книги: ";
        getline(cin, title);
        cout << "Введите цену книги: ";
        cin >> price;
        cin.ignore(); 
    }

    // Виртуальный метод для вывода данных
    virtual void putdata() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << endl;
    }

    // Виртуальный деструктор для корректного наследования
    virtual ~Publication() {}
};

// Класс book, наследник Publication
class Book : public Publication {
private:
    int pageCount;  // Количество страниц

public:
    // Переопределенный метод для ввода данных
    void getdata() override {
        Publication::getdata();  // Вводим данные базового класса
        cout << "Введите количество страниц: ";
        cin >> pageCount;
        cin.ignore(); // Игнорируем символ новой строки
    }

    // Переопределенный метод для вывода данных
    void putdata() const override {
        Publication::putdata();  // Выводим данные базового класса
        cout << "Количество страниц: " << pageCount << endl;
    }
};

// Класс type, наследник Publication
class Type : public Publication {
private:
    float recordingTime;  // Время записи в минутах

public:
    // Переопределенный метод для ввода данных
    void getdata() override {
        Publication::getdata();  // Вводим данные базового класса
        cout << "Введите время записи (в минутах): ";
        cin >> recordingTime;
        cin.ignore(); 
    }

    // Переопределенный метод для вывода данных
    void putdata() const override {
        Publication::putdata();  // Выводим данные базового класса
        cout << "Время записи: " << recordingTime << " минут" << endl;
    }
};

int main() {
    // Создаем объекты класса Book и Type
    Book myBook;
    Type myAudio;

    // Вводим данные для книги
    cout << "Введите информацию о книге:" << endl;
    myBook.getdata();

    // Вводим данные для аудиозаписи
    cout << "\nВведите информацию об аудиозаписи:" << endl;
    myAudio.getdata();

    // Выводим данные
    cout << "\nИнформация о книге:" << endl;
    myBook.putdata();

    cout << "\nИнформация об аудиозаписи:" << endl;
    myAudio.putdata();

    return 0;
}
