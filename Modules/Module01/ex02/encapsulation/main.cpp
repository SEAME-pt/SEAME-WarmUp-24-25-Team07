#include "Car.hpp"
#include "SportCar.hpp"

int main() {
    // Using Car class with encapsulated access
    Car car1("Fiat", "Uno", 2022);
    car1.drive();
    car1.setYear(2023); // Using setter to change the year
    std::cout << "Updated Car Year: " << car1.getModel() << " " << car1.getYear() << std::endl; // Using getter to retrieve the year

    // Using SportsCar class with encapsulated access
    SportCar sportsCar1("Ferrari", "488", 2021, 330);
    sportsCar1.drive();
    sportsCar1.setMaxSpeed(350);
    std::cout << "Updated Top Speed of SportsCar: " << sportsCar1.getMaxSpeed() << " km/h" << std::endl; // Using getter to retrieve topSpeed

    return 0;
}