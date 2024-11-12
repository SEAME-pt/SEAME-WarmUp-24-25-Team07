#include "car.hpp"

int main() {
    Car car1;
    Car car2("Toyota", "Corolla", 2015);
    Car car3 = car2;

    car1.drive();
    car2.drive();
    car3.drive();

    return 0;
}