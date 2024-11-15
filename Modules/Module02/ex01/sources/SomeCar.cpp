#include "../includes/SomeCar.hpp"
#include "../includes/partAll.hpp"


// Constructors
SomeCar::SomeCar() : ACar(), _maxSpeed(0) {
    std::cout << "Default constructor called for SomeCar" << std::endl;
    _body = new partBody();
    _brakes = new partBrake[4];
    _chassis = new partChassis();
    _doors = new partDoor[4];
    _engine = new partEngine();
    _mediaSystem = new partMediaSystem();
    _seats = new partSeat[4];
    _tires = new partTire[4];
    _transmission = new partTransmission();
    _trunk = new partTrunk();
    _wheels = new partWheel[4];
    _windShield = new partWindShield();
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
    delete _body;
    delete [] _brakes;
    delete _chassis;
    delete [] _doors;
    delete _engine;
    delete _mediaSystem;
    delete [] _seats;
    delete [] _tires;
    delete _transmission;
    delete _trunk;
    delete [] _wheels;
    delete _windShield;
}

// Member function
void SomeCar::drive() const {
    std::cout << "Driving some car: " << _make << " " << _model << " " << _year << " edition at " << _maxSpeed << " km/h." << std::endl;
}

void SomeCar::printParts(void) const {
    _body->print();
    for (int i = 0; i < 4; ++i) _brakes[i].print(i);
    _chassis->print();
    _engine->print();
    _mediaSystem->print();
    for (int i = 0; i < 4; ++i) _seats[i].print(i);
    for (int i = 0; i < 4; ++i) _tires[i].print(i);
    _transmission->print();
    _trunk->print();
    for (int i = 0; i < 4; ++i) _wheels[i].print(i);
    _windShield->print();
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
