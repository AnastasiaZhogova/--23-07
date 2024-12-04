#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Базовый класс "Деталь"
class Detail {
protected:
    string name;
    int id;

    // Конструкторы защищённые
    Detail(const string& n, int i) : name(n), id(i) {}
    Detail() : name("Нет имени"), id(0) {}

public:
    virtual void display() const {  // виртуальный метод для демонстрации полиморфизма
        cout << "Деталь: " << name << " (ID: " << id << ")" << endl;
    }

    virtual ~Detail() = default;  // виртуальный деструктор по умолчанию

    // Шаблонная дружественная функция для создания объектов
    template<typename T>
    friend T* createEntity(const string& n, int i);
};

// Производный класс "Сборка"
class Assembly : public Detail {
protected:
    int componentCount;

    Assembly(const string& n, int i, int count) : Detail(n, i), componentCount(count) {}
    Assembly() : Detail(), componentCount(0) {}

public:
    void display() const override {  // переопределение виртуальной функции
        cout << "Сборка: " << name << " (ID: " << id << "), количество компонентов: "
            << componentCount << endl;
    }

    template<typename T>
    friend T* createEntity(const string& n, int i);  // та же дружественная функция
};

// Шаблонная функция для создания объектов
template<typename T>
T* createEntity(const string& n, int i) {
    if constexpr (is_same_v<T, Detail>) {
        return new Detail(n, i);
    }
    else if constexpr (is_same_v<T, Assembly>) {
        // Генерация случайного количества компонентов
        return new Assembly(n, i, rand() % 9 + 2);
    }
    return nullptr;
}

int main() {
    setlocale(LC_ALL, "Russian");  // поддержка русского языка
    srand(static_cast<unsigned>(time(nullptr)));  // инициализация генератора случайных чисел

    // Вектор указателей на объекты базового класса
    vector<Detail*> warehouse;

    // Создание объектов и добавление их в вектор
    warehouse.push_back(createEntity<Detail>("Шайба", 1));
    warehouse.push_back(createEntity<Detail>("Подшипник", 2));
    warehouse.push_back(createEntity<Detail>("Распредвал", 3));
    warehouse.push_back(createEntity<Assembly>("Коробка передач", 4));

    // Вывод информации об объектах
    cout << "Содержимое склада:" << endl;
    for (const auto& element : warehouse) {
        element->display();
    }

    // Освобождение памяти
    for (auto& element : warehouse) {
        delete element;
    }

    return 0;
}
