#include "SportCar.hpp"

// Constructors
SportCar::SportCar() : ACar(), _maxSpeed(0) {
    std::cout << "Default constructor called for SportCar" << std::endl;
}

SportCar::SportCar(const std::string& make, const std::string& model, int year, int maxSpeed)
    : ACar(make, model, year), _maxSpeed(maxSpeed) {
    std::cout << "Parameterized constructor called for SportCar: " << make << " " << model << " " << year << " " << maxSpeed << std::endl;
}

SportCar::SportCar(const SportCar& other) : ACar(other), _maxSpeed(other._maxSpeed) {
    std::cout << "Copy constructor called for SportCar" << std::endl;
}

// Destructor
SportCar::~SportCar() {
    std::cout << "Destructor called for SportCar" << std::endl;
}

// Member function
void SportCar::drive() const {
    std::cout << "Driving a sport car: " << _make << " " << _model << " (" << _year << ") at " << _maxSpeed << " km/h!" << std::endl;
}

std::string SportCar::getInfo() const {
    return _make + " " + _model + " (" + std::to_string(_year) + "), Max Speed: " + std::to_string(_maxSpeed) << std::endl;
}

// Operator overload
SportCar& SportCar::operator=(const SportCar& other) {
    if (this != &other) {
        ACar::operator=(other);
        _maxSpeed = other._maxSpeed;
    }
    std::cout << "Copy assignment operator called for SportCar" << std::endl;
    return *this;
}

std::ostream& operator<<(std::ostream& o, const SportCar& i) {
    o << i.getInfo();
    return o;
}