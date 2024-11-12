#include "car_functions.hpp"
#include <iostream>

void showCarInfo(const ACar& car) {
    std::cout << car.getInfo();
}

void driveCar(const ACar* car) {
    car->drive();
}
