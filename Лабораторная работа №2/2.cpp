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

// Базовый класс Sales
class Sales {
protected:
    float sales[3];  // Продажи за последние три месяца

public:
    // Метод для ввода данных о продажах
    void getdata() {
        cout << "Введите продажи за последние три месяца:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << i + 1 << ": ";
            cin >> sales[i];
        }
        cin.ignore();
    }

    // Метод для вывода данных о продажах
    void putdata() const {
        cout << "Продажи за последние три месяца:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << i + 1 << ": " << sales[i] << endl;
        }
    }
};

// Класс Book, наследник Publication и Sales
class Book : public Publication, public Sales {
private:
    int pageCount;  // Количество страниц

public:
    // Переопределенный метод для ввода данных
    void getdata() override {
        Publication::getdata();  // Вводим данные базового класса Publication
        cout << "Введите количество страниц: ";
        cin >> pageCount;
        cin.ignore(); 
        Sales::getdata();  // Вводим данные о продажах
    }

    // Переопределенный метод для вывода данных
    void putdata() const override {
        Publication::putdata();  // Выводим данные базового класса Publication
        cout << "Количество страниц: " << pageCount << endl;
        Sales::putdata();  // Выводим данные о продажах
    }
};

// Класс Type, наследник Publication и Sales
class Type : public Publication, public Sales {
private:
    float recordingTime;  // Время записи в минутах

public:
    // Переопределенный метод для ввода данных
    void getdata() override {
        Publication::getdata();  // Вводим данные базового класса Publication
        cout << "Введите время записи (в минутах): ";
        cin >> recordingTime;
        cin.ignore();
        Sales::getdata();  // Вводим данные о продажах
    }

    // Переопределенный метод для вывода данных
    void putdata() const override {
        Publication::putdata();  // Выводим данные базового класса Publication
        cout << "Время записи: " << recordingTime << " минут" << endl;
        Sales::putdata();  // Выводим данные о продажах
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
