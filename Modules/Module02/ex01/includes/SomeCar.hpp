#pragma once

#include "ACar.hpp"
#include "partAll.hpp"

#include <iostream>

class SomeCar : public ACar {
    private:
        int _maxSpeed;
        partBody* _body;
        partBrake* _brakes;
        partChassis* _chassis;
        partDoor* _doors;
        partEngine* _engine;
        partMediaSystem* _mediaSystem;
        partSeat* _seats;
        partTire* _tires;
        partTransmission* _transmission;
        partTrunk* _trunk;
        partWheel* _wheels;
        partWindShield* _windShield;

    public:
        SomeCar();
        SomeCar(const std::string& make, const std::string& model, const unsigned int year, const unsigned int maxSpeed);
        SomeCar(const SomeCar& other);
        SomeCar& operator=(const SomeCar& other);
        ~SomeCar();

        void drive() const;
        void printParts() const;

};

std::ostream &  operator<<( std::ostream & o, SomeCar & i );
