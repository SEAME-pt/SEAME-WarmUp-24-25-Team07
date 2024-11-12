#ifndef SEDANCAR_HPP
#define SEDANCAR_HPP

#include <iostream>
#include "ACar.hpp"

class SedanCar : public ACar {
    private:
        int _maxSpeed;
    public:
        SedanCar();
        SedanCar(const std::string& make, const std::string& model, int year, int maxSpeed);
        SedanCar(const SedanCar& other);
        SedanCar& operator=(const SedanCar& other);
        virtual ~SedanCar();

        void drive() const;
        std::string getInfo() const;
};

std::ostream &  operator<<( std::ostream & o, SedanCar & i );

#endif