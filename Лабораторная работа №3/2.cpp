#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <sstream>

// Реализация to_string для совместимости
template <typename T>
std::string to_string(T value) {
    std::ostringstream buffer;
    buffer << value;
    return buffer.str();
}

class BaseClass {
protected:
    int number;
public:
    BaseClass() : number(rand() % 100) {
        std::cout << "[BaseClass]: Создан объект с числом: " << number << std::endl;
    }

    virtual ~BaseClass() {
        std::cout << "[BaseClass]: Уничтожен объект с числом: " << number << std::endl;
    }

    virtual void displayInfo() const {
        std::cout << "Базовый объект с числом: " << number << std::endl;
    }

    virtual BaseClass* createCopy() const {
        return new BaseClass(*this);
    }
};

class DerivedClass : public BaseClass {
    std::string identifier;
public:
    DerivedClass() : identifier("Элемент-" + to_string(rand() % 1000)) {
        std::cout << "[DerivedClass]: Создан объект с именем: " << identifier << std::endl;
    }

    ~DerivedClass() override {
        std::cout << "[DerivedClass]: Уничтожен объект с именем: " << identifier << std::endl;
    }

    void displayInfo() const override {
        std::cout << "Производный объект с числом: " << number << ", именем: " << identifier << std::endl;
    }

    BaseClass* createCopy() const override {
        return new DerivedClass(*this);
    }
};

class ObjectStorage {
    std::vector<std::unique_ptr<BaseClass>> elements;
public:
    void addObject(BaseClass* object) {
        elements.push_back(std::unique_ptr<BaseClass>(object));
    }

    size_t count() const {
        return elements.size();
    }

    void displayAll() const {
        for (const auto& element : elements) {
            element->displayInfo();
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned>(time(nullptr)));
    ObjectStorage storage;

    const int totalObjects = 5;
    std::cout << "\nИнициализация объектов:\n";
    for (int i = 0; i < totalObjects; ++i) {
        BaseClass* temp;
        if (rand() % 2 == 0) {
            temp = new BaseClass();
        }
        else {
            temp = new DerivedClass();
        }
        storage.addObject(temp->createCopy());
        delete temp;
    }

    std::cout << "\nВывод всех объектов:\n";
    storage.displayAll();

    return 0;
}
