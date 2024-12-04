#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>
#include <locale>
// Базовый класс Person
class Person {
public:
    virtual void info() const = 0; // Виртуальная функция
    virtual ~Person() = default;
};

// Классы-наследники
class Preschooler : public Person {
public:
    void info() const override {
        std::cout << "Я дошкольник." << std::endl;
    }
};

class Schooler : public Person {
public:
    void info() const override {
        std::cout << "Я школьник." << std::endl;
    }
};

class Student : public Person {
public:
    void info() const override {
        std::cout << "Я студент." << std::endl;
    }
};

class Worker : public Person {
public:
    void info() const override {
        std::cout << "Я работающий." << std::endl;
    }
};

// Шаблонный класс Array
template <typename T>
class Array {
private:
    std::vector<std::shared_ptr<T>> elements;
    size_t max_size;

public:
    // Конструктор
    Array(size_t max_size) : max_size(max_size) {
        if (max_size > 1000) { // Ограничение на размер
            throw std::length_error("Размер массива превышает допустимый максимум!");
        }
    }

    // Добавление элемента
    void add(std::shared_ptr<T> element) {
        if (elements.size() >= max_size) {
            throw std::length_error("Массив заполнен!");
        }
        elements.push_back(element);
    }

    // Перегрузка оператора []
    std::shared_ptr<T> operator[](size_t index) const {
        if (index >= elements.size()) {
            throw std::out_of_range("Индекс вне диапазона!");
        }
        return elements[index];
    }

    // Размер массива
    size_t size() const {
        return elements.size();
    }
};

// Демонстрация работы
int main() {
    setlocale(LC_ALL, "Rus");
    try {
        // Создаем массив указателей на Person
        Array<Person> persons(5);

        persons.add(std::make_shared<Preschooler>());
        persons.add(std::make_shared<Schooler>());
        persons.add(std::make_shared<Student>());
        persons.add(std::make_shared<Worker>());

        // Вывод информации о каждом элементе
        std::cout << "Список объектов:" << std::endl;
        for (size_t i = 0; i < persons.size(); ++i) {
            persons[i]->info();
        }

        // Попытка создать массив слишком большого размера
        std::cout << "Попытка создать слишком большой массив..." << std::endl;
        Array<int> bigArray(2000);

    }
    catch (const std::length_error& e) {
        std::cerr << "Ошибка размера: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}
