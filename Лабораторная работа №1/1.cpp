#include <iostream>
using namespace std;

int main() {
    // Изменяем кодировку консоли на Windows-1251 для корректного отображения текста
    system("chcp 1251 > nul");

    // Создаем динамический массив из 10 элементов типа double
    double* arr = new double[10];

    // Заполняем массив значениями
    for (int i = 0; i < 10; ++i) {
        arr[i] = i * 1.1;  // Например: 0.0, 1.1, 2.2, и т.д.
    }

    // Выводим содержимое массива
    cout << "Содержимое массива: ";
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Выводим адрес начала массива
    cout << "Адрес начала массива: " << arr << endl;

    // Выводим расстояние каждого элемента от начала массива
    cout << "Расстояние каждого элемента от начала массива (в байтах):" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Элемент " << i << ": " << (reinterpret_cast<char*>(&arr[i]) - reinterpret_cast<char*>(arr)) << " байт" << endl;
    }

    // Освобождаем память
    delete[] arr;

    return 0;
}
