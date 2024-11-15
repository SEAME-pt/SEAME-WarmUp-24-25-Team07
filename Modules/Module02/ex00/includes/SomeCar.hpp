#pragma once
#include "ACar.hpp"
#include <iostream>

class SomeCar : public ACar {
    private:
        int _maxSpeed;
    public:
        SomeCar();
        SomeCar(const std::string& make, const std::string& model, const unsigned int year, const unsigned int maxSpeed);
        SomeCar(const SomeCar& other);
        SomeCar& operator=(const SomeCar& other);
        virtual ~SomeCar();

        void drive() const;
};

std::ostream &  operator<<( std::ostream & o, SomeCar & i );
