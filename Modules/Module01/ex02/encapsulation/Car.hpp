#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>

class Car {
protected:
    std::string _make;
    std::string _model;
    int _year;

public:
    Car();
    Car(const std::string& make, const std::string& model, int year);
    Car(const Car& other);
    Car& operator=(const Car& other);
    virtual ~Car();

    const std::string& getMake() const;
    const std::string& getModel() const;
    int getYear() const;

    void setMake(const std::string& make);
    void setModel(const std::string& model);
    void setYear(int year);

    virtual void drive() const;
};

std::ostream &  operator<<( std::ostream & o, Car & i );

#endif
