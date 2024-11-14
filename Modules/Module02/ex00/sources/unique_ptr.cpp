#include "../includes/partSomeCar.hpp"
#include <iostream>
#include <memory>  // For smart pointers

void createCarWithUniquePtr() {
    std::unique_ptr<SomeCar> car = std::make_unique<SomeCar>("Tesla", "Model S", 2024, 250);
    car->drive();
    // No need to manually delete car, it's automatically destroyed when going out of scope.
}

int main() {
    createCarWithUniquePtr();
    // car is automatically deleted when it goes out of scope here
    return 0;
}
