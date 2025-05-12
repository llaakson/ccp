#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice(){}

Ice::Ice(const Ice &copy) : AMateria(copy){}

Ice& Ice::operator=(const Ice &rhs){
	if (this != &rhs)
	{
		return (*this);
	}
	return (*this);
}

AMateria* Ice::clone() const
{
		return(new Ice);
}