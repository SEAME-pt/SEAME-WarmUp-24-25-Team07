#ifndef SPORTCAR_HPP
#define SPORTCAR_HPP

#include <iostream>
#include "Car.hpp"

class SportCar : public Car {
    private:
        int _maxSpeed;
    public:
        SportCar();
        SportCar(const std::string& make, const std::string& model, int year, int maxSpeed);
        SportCar(const SportCar& other);
        SportCar& operator=(const SportCar& other);
        virtual ~SportCar();

        int getMaxSpeed() const;

        void setMaxSpeed(int maxSpeed);

        virtual void drive() const;
};

std::ostream &  operator<<( std::ostream & o, SportCar & i );

#endif