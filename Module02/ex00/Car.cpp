class Car {
public:
    Car(const std::string& model) : model_(model) {
        std::cout << "Car " << model_ << " created." << std::endl;
    }

    ~Car() {
        std::cout << "Car " << model_ << " destroyed." << std::endl;
    }

    void drive() {
        std::cout << "Driving the " << model_ << " car." << std::endl;
    }

private:
    std::string model_;
};