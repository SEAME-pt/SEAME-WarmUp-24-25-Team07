#include "SportCar.hpp"
#include "SedanCar.hpp"
#include "car_functions.hpp"
#include <iostream>

int main() {

    SportCar ferrari("Ferrari", "488", 2021, 330);
    SportCar porsche("Porsche", "911 Turbo", 2022, 320);


    showCarInfo(ferrari);
    showCarInfo(porsche);

    ACar* car1 = new SportCar("Lamborghini", "Aventador", 2023, 350);
    ACar* car2 = new SedanCar("Toyota", "Corolla", 2023, 200);
    driveCar(car1);
    driveCar(car2);

    delete car1;
    delete car2;

    return 0;
}
