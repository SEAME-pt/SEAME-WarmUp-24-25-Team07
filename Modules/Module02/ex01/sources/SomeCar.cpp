#include "SomeCar.hpp"
#include "../includes/partEngine.hpp"
#include "../includes/partWheel.hpp"
#include "../includes/partTransmission.hpp"
#include "../includes/partBreak.hpp"

// Constructors
SomeCar::SomeCar() : ACar(), _maxSpeed(0) {
    std::cout << "Default constructor called for SomeCar" << std::endl;
    _engine = new Engine();
    _wheels = new Wheel[4];
    _brakes = new Brake[4];
    _transmission = new Transmission();
}

SomeCar::SomeCar(const std::string& make, const std::string& model, const unsigned int year, const unsigned int maxSpeed)
    : ACar(make, model, year), _maxSpeed(maxSpeed) {
    std::cout << "Parameterized constructor called for SomeCar: " << make << " " << model << " " << year << " " << maxSpeed << std::endl;
}

SomeCar::SomeCar(const SomeCar& original) : ACar(original), _maxSpeed(original._maxSpeed) {
    std::cout << "Copy constructor called for SomeCar" << std::endl;
}

// Destructor
SomeCar::~SomeCar() {
    std::cout << "Destructor called for SomeCar" << std::endl;
    delete _engine;
    delete [] _wheels;
    delete [] _brakes;
    delete _transmission;
}

// Member function
void SomeCar::drive() const {
    std::cout << "Driving some car: " << _make << " " << _model << " " << _year << " edition at " << _maxSpeed << " km/h." << std::endl;
}

void SomeCar::printParts(void) const {
    _engine->print();
    for (int i = 0; i < 4; ++i) {
        _wheels[i].print();
        _brakes[i].print();
    }
    _transmission->print();
}

// Operator overload
SomeCar& SomeCar::operator=(const SomeCar& original) {
    if (this != &original) {
        ACar::operator=(original);
        _maxSpeed = original._maxSpeed;
    }
    std::cout << "Copy assignment operator called for SomeCar" << std::endl;
    return *this;
}
