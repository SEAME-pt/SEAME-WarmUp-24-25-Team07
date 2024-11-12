#include "Car.hpp"
#include <iostream>
#include <memory>  // For smart pointers

void createCarWithUniquePtr() {
    std::unique_ptr<Car> car = std::make_unique<Car>("Tesla Model S");
    car->drive();
    // No need to manually delete car, it's automatically destroyed when going out of scope.
}

int main() {
    createCarWithUniquePtr();
    // car is automatically deleted when it goes out of scope here
    return 0;
}
