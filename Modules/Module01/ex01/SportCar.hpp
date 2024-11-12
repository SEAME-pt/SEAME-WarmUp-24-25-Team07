#ifndef SPORTCAR_HPP
#define SPORTCAR_HPP

#include <iostream>
#include "car.hpp"

class SportCar : public Car {
    private:
        int _maxSpeed;
    public:
        SportCar();
        SportCar(const std::string& make, const std::string& model, int year, int maxSpeed);
        SportCar(const SportCar& other);
        SportCar& operator=(const SportCar& other);
        virtual ~SportCar();

        void drive() const;
};

std::ostream &  operator<<( std::ostream & o, SportCar & i );

#endif