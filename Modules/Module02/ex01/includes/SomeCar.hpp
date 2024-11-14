#pragma once

#include "ACar.hpp"
#include "Transmission.hpp"
#include "Engine.hpp"
#include "Wheel.hpp"
#include "Break.hpp"

#include <iostream>

class SomeCar : public ACar {
    private:
        int _maxSpeed;
        Engine* _engine;
        Wheel* _wheels;
        Brake* _brakes;
        Transmission* _transmission;
    public:
        SomeCar();
        SomeCar(const std::string& make, const std::string& model, const unsigned int year, const unsigned int maxSpeed);
        SomeCar(const SomeCar& other);
        SomeCar& operator=(const SomeCar& other);
        virtual ~SomeCar();

        void drive() const;
        void printParts() const

};

std::ostream &  operator<<( std::ostream & o, SomeCar & i );
