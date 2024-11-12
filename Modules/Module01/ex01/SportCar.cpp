#include "SportCar.hpp"

// Constructors
SportCar::SportCar() : Car(), _maxSpeed(0) {
    std::cout << "Default constructor called for SportCar" << std::endl;
}

SportCar::SportCar(const std::string& make, const std::string& model, int year, int maxSpeed)
    : Car(make, model, year), _maxSpeed(maxSpeed) {
    std::cout << "Parameterized constructor called for SportCar: " << make << " " << model << " " << year << " " << maxSpeed << std::endl;
}

SportCar::SportCar(const SportCar& other) : Car(other), _maxSpeed(other._maxSpeed) {
    std::cout << "Copy constructor called for SportCar" << std::endl;
}

// Destructor
SportCar::~SportCar() {
    std::cout << "Destructor called for SportCar" << std::endl;
}

// Member function
void SportCar::drive() const {
    std::cout << "Driving " << _make << " " << _model << " " << _year << " edition at " << _maxSpeed << " km/h." << std::endl;
}

// Operator overload
SportCar& SportCar::operator=(const SportCar& other) {
    if (this != &other) {
        Car::operator=(other);
        _maxSpeed = other._maxSpeed;
    }
    std::cout << "Copy assignment operator called for SportCar" << std::endl;
    return *this;
}