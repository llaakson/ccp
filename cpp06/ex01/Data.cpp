#include "Data.hpp"

Data::Data() : _name("Pikachu"), _number(25), _type("Electric"){}

Data::Data(const Data &copy){
    _name = copy._name;
    _number = copy._number;
    _type = copy._number;
}

Data& Data::operator=(const Data &rhs){
    if(this != &rhs)
    {
        _name = rhs._name;
        _number = rhs._number;
        _type = rhs._number;
    }
    return *this;
}

void Data::open_datadex(){
    std::cout << "Name: " <<_name << " Number: " << _number << " Type: " << _type << std::endl;
}

Data::~Data(){}