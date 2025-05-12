#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){}

Cure::~Cure(){}

Cure::Cure(const Cure &copy) : AMateria(copy){}

Cure& Cure::operator=(const Cure &rhs){
	if (this != &rhs)
	{
		return (*this);
	}
	return (*this);
}

AMateria* Cure::clone() const
{
		return(new Cure);
}

