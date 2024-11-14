#include "Car.hpp"


// Constructors
Car::Car() : _make("Default"), _model("Default"), _year(0) {
    std::cout << "Default constructor called for Car" << std::endl;
}

Car::Car(const std::string& make, const std::string& model, int year)
    : _make(make), _model(model), _year(year) {
    std::cout << "Parameterized constructor called for Car: " << make << " " << model << " " << year << std::endl;
}

Car::Car(const Car& other) : _make(other._make), _model(other._model), _year(other._year) {
    std::cout << "Copy constructor called for Car" << std::endl;
}


// Destructor
Car::~Car() {
    std::cout << "Destructor called for Car" << std::endl;
}

// Member function
void Car::drive() const {
    std::cout << "Driving " << _make << " " << _model << " " << _year << " edition." << std::endl;
}

// Getters
const std::string& Car::getMake() const {
    return _make;
}

const std::string& Car::getModel() const {
    return _model;
}

int Car::getYear() const {
    return _year;
}

// Setters
void Car::setMake(const std::string& make) {
    _make = make;
}

void Car::setModel(const std::string& model) {
    _model = model;
}

void Car::setYear(int year) {
    _year = year;
}


// Operator overload
Car& Car::operator=(const Car& other) {
    if (this != &other) {
        _make = other._make;
        _model = other._model;
        _year = other._year;
    }
    std::cout << "Copy assignment operator called for Car" << std::endl;
    return *this;
}
std::ostream &  operator<<( std::ostream & o, Car & i ) {
    o << i.getMake() << " " << i.getModel() << " " << i.getYear();
    return o;
}