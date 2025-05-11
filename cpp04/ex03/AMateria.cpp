#include "AMateria.hpp"

AMateria::AMateria() : _type("DefaultType"){}

AMateria::AMateria(std::string const & type)
{
    _type = type; 
}
AMateria::AMateria(const AMateria &copy)
{

}
AMateria& AMateria::operator=(const AMateria &rhs)
{
    if (this != &rhs)
    {
        _type = rhs._type;
    }
}
std::string const &AMateria::getType() const
{
    return (_type);
}
AMateria* AMateria::clone() const
{

}
void AMateria::use(ICharacter& target)
{

}
AMateria::~AMateria()
{

}