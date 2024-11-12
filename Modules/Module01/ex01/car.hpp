#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>

class Car {
protected:
    std::string _make;
    std::string _model;
    int _year;

public:
    Car();
    Car(const std::string& make, const std::string& model, int year);
    Car(const Car& other);
    Car& operator=(const Car& other);
    virtual ~Car();

    virtual void drive() const;
};

std::ostream &  operator<<( std::ostream & o, Car & i );

#endif
