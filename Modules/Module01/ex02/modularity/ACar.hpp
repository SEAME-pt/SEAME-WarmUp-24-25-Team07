#ifndef ACAR_HPP
#define ACAR_HPP

#include <iostream>
#include <string>

class ACar {
protected:
    std::string _make;
    std::string _model;
    int _year;

public:
    ACar();
    ACar(const std::string& make, const std::string& model, int year);

    ACar(const ACar& other);
    ACar& operator=(const ACar& other);

    virtual void drive() const = 0;
    virtual std::string getInfo() const = 0;

    virtual ~ACar();
};

#endif
