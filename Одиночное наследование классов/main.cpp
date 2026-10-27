
#include <iostream>
#include <string>
#include <locale>

using namespace std;

// Базовый класс гостиничного номера
class Room {
protected:
    int roomNumber;
    int floor;
    int capacity;
    double pricePerNight;

public:
    Room(int number, int floor, int capacity, double price)
        : roomNumber(number),
          floor(floor),
          capacity(capacity),
          pricePerNight(price) {}

    virtual void displayInfo() const {
        cout << "Номер комнаты: " << roomNumber << endl;
        cout << "Этаж: " << floor << endl;
        cout << "Количество мест: " << capacity << endl;
        cout << "Цена за сутки: " << pricePerNight << " руб." << endl;
    }

    virtual double calculateCost(int days) const {
        return pricePerNight * days;
    }

    virtual ~Room() = default;
};

// Производный класс стандартного номера
class StandardRoom : public Room {
private:
    bool hasTV;

public:
    StandardRoom(int number, int floor, int capacity,
                 double price, bool tv)
        : Room(number, floor, capacity, price),
          hasTV(tv) {}

    void displayInfo() const override {
        cout << "\n=== Стандартный номер ===" << endl;
        Room::displayInfo();
        cout << "Телевизор: "
             << (hasTV ? "есть" : "нет") << endl;
    }
};

// Производный класс номера Люкс
class LuxuryRoom : public Room {
private:
    bool hasJacuzzi;

public:
    LuxuryRoom(int number, int floor, int capacity,
               double price, bool jacuzzi)
        : Room(number, floor, capacity, price),
          hasJacuzzi(jacuzzi) {}

    void displayInfo() const override {
        cout << "\n=== Номер Люкс ===" << endl;
        Room::displayInfo();
        cout << "Джакузи: "
             << (hasJacuzzi ? "есть" : "нет") << endl;
    }
};

// Производный класс семейного номера
class FamilyRoom : public Room {
private:
    bool hasKitchen;

public:
    FamilyRoom(int number, int floor, int capacity,
               double price, bool kitchen)
        : Room(number, floor, capacity, price),
          hasKitchen(kitchen) {}

    void displayInfo() const override {
        cout << "\n=== Семейный номер ===" << endl;
        Room::displayInfo();
        cout << "Кухня: "
             << (hasKitchen ? "есть" : "нет") << endl;
    }
};

int main() {
    setlocale(LC_ALL, "");

    StandardRoom standard(101, 1, 2, 3000, true);
    LuxuryRoom luxury(205, 2, 2, 8500, true);
    FamilyRoom family(310, 3, 4, 6000, true);

    const int days = 3;

    standard.displayInfo();
    cout << "Стоимость за " << days << " суток: "
         << standard.calculateCost(days) << " руб." << endl;

    luxury.displayInfo();
    cout << "Стоимость за " << days << " суток: "
         << luxury.calculateCost(days) << " руб." << endl;

    family.displayInfo();
    cout << "Стоимость за " << days << " суток: "
         << family.calculateCost(days) << " руб." << endl;

    return 0;
}
