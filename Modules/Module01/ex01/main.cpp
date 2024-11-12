#include "car.hpp"
#include "SportCar.hpp"

int main() {
    Car car1;
    Car car2("Toyota", "Corolla", 2015);
    Car car3 = car2;

    car1.drive();
    car2.drive();
    car3.drive();

    SportCar sportCar1;
    SportCar sportCar2("Ferrari", "F8", 2020, 300);
    SportCar sportCar3 = sportCar2;

    sportCar1.drive();
    sportCar2.drive();
    sportCar3.drive();

    return 0;
}