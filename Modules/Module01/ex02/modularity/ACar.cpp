
#include "ACar.hpp"
#include <iostream>

ACar::ACar() : _make("Unknown"), _model("Unknown"), _year(0) {}

ACar::ACar(const std::string& _make, const std::string& _model, int _year)
    : _make(_make), _model(_model), _year(_year) {}

ACar::ACar(const ACar& other) : _make(other._make), _model(other._model), _year(other._year) {}

ACar& ACar::operator=(const ACar& other) {
    if (this != &other) {
        _make = other._make;
        _model = other._model;
        _year = other._year;
    }
    return *this;
}

ACar::~ACar() {}
