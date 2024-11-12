#include "SportCar.hpp"
#include "SedanCar.hpp"
#include <iostream>

int main() {
    SportCar ferrari("Ferrari", "488", 2021, 330);
    SportCar porsche("Porsche", "911", 2022, 320);

    ACar* car1 = new SportCar("Lamborghini", "Aventador", 2023, 350);
    ACar* car2 = new SportCar("Bugatti", "Chiron", 2022, 420);

    car1->drive();
    car2->drive();

    std::cout << ferrari << std::endl;
    std::cout << porsche << std::endl;

    std::cout << "Ferrari info: " << ferrari.getInfo() << std::endl;
    std::cout << "Porsche info: " << porsche.getInfo() << std::endl;


    SedanCar corolla("Toyota", "Corolla", 2003, 240);

    ACar* car3 = new SedanCar("Ford", "Focus", 2008, 200);

    car3->drive();

    delete car1;
    delete car2;

    return 0;
}
