#pragma once
#include <iostream>
#include <string>

class Part
{
    private:
        std::string _partName;
    public:
        Part();
        Part(const std::string partName);
        Part(const Part & original);
        ~Part();

        virtual void print() = 0;
}

std::ostream &  operator<<( std::ostream & o, Part & i );

    ACar();
    ACar(const std::string& make, const std::string& model, const unsigned int year);

    ACar(const ACar& original);
    ACar& operator=(const ACar& original);

    virtual void drive() const = 0;
    virtual std::string getInfo() const = 0;

    virtual ~ACar();