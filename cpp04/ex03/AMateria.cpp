#include "AMateria.hpp"

AMateria::AMateria() : _type("DefaultType"){}

AMateria::AMateria(std::string const & type) : _type(type)
{

}
AMateria::AMateria(const AMateria &copy)
{
    *this = copy;
}
AMateria& AMateria::operator=(const AMateria &rhs)
{
    if (this != &rhs)
    {
        return (*this);
    }
    return(*this);
}
std::string const &AMateria::getType() const
{
    return (_type);
}
AMateria* AMateria::clone() const
{
   return(NULL);
}
void AMateria::use(ICharacter& target)
{
    //std::cout << _type << std::endl;
    if (_type == "ice")
        std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;;
    if (_type == "cure")
        std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
AMateria::~AMateria()
{

}