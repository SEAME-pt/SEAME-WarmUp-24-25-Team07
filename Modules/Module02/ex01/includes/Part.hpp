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
        virtual ~Part() = 0;

        virtual void print() = 0;
}
