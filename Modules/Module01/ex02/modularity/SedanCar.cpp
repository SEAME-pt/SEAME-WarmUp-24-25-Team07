#include "SedanCar.hpp"

// Constructors
SedanCar::SedanCar() : ACar(), _maxSpeed(0) {
    std::cout << "Default constructor called for SedanCar" << std::endl;
}

SedanCar::SedanCar(const std::string& make, const std::string& model, int year, int maxSpeed)
    : ACar(make, model, year), _maxSpeed(maxSpeed) {
    std::cout << "Parameterized constructor called for SedanCar: " << make << " " << model << " " << year << " " << maxSpeed << std::endl;
}

SedanCar::SedanCar(const SedanCar& other) : ACar(other), _maxSpeed(other._maxSpeed) {
    std::cout << "Copy constructor called for SedanCar" << std::endl;
}

// Destructor
SedanCar::~SedanCar() {
    std::cout << "Destructor called for SedanCar" << std::endl;
}

// Member function
void SedanCar::drive() const {
    std::cout << "Driving a sedan car: " << _make << " " << _model << " (" << _year << ") at " << _maxSpeed << " km/h!" << std::endl;
}

std::string SedanCar::getInfo() const {
    return _make + " " + _model + " (" + std::to_string(_year) + "), Max Speed: " + std::to_string(_maxSpeed)  + " km/h\n";
}

// Operator overload
SedanCar& SedanCar::operator=(const SedanCar& other) {
    if (this != &other) {
        ACar::operator=(other);
        _maxSpeed = other._maxSpeed;
    }
    std::cout << "Copy assignment operator called for SedanCar" << std::endl;
    return *this;
}

std::ostream& operator<<(std::ostream& o, const SedanCar& i) {
    o << i.getInfo();
    return o;
}