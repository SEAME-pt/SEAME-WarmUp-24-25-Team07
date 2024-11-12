#include "ACar.hpp"
#include "SportCar.hpp"
#include "SedanCar.hpp"

int main() {

    ACar* car1 = new SportCar("Ferrari", "f40", 2000, 300);
    ACar* car2 = new SedanCar("Toyota", "Corolla", 2009, 240);

    car1->drive();
    car2->drive();

    delete car1;
    delete car2;

    return 0;
}