#include "../includes/SomeCar.hpp"
#include <iostream>
#include <memory>  // For smart pointers

void createCarWithSharedPtr() {
    std::shared_ptr<SomeCar> car1 = std::make_shared<SomeCar>("BMW", "M3", 2024, 250);
    {
        std::shared_ptr<SomeCar> car2 = car1;  // Now both car1 and car2 point to the same object
        car2->drive();
        // car2 goes out of scope, but the car is still owned by car1
    }
    car1->drive();
    // car1 goes out of scope and the car is destroyed when it's no longer referenced
}

int main() {
    createCarWithSharedPtr();
    // Car is automatically destroyed here when car1 goes out of scope
    return 0;
}
