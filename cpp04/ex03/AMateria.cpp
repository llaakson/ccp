#include "AMateria.hpp"
#include <string>

AMateria::AMateria() : _type("DefaultType"){}

AMateria::AMateria(std::string const & type) : _type(type){}

AMateria::AMateria(const AMateria &copy)
{
    this->_type = copy._type;
}

AMateria& AMateria::operator=(const AMateria &rhs)
{
    if (this != &rhs)
    {
        _type = rhs._type;
    }
    return(*this);
}

std::string const &AMateria::getType() const
{
    return (_type);
}

void AMateria::use(ICharacter& target)
{
    if (_type == "ice")
        std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;;
    if (_type == "cure")
        std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria::~AMateria(){}