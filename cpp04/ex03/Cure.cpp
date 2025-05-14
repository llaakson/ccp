#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){}

Cure::~Cure(){}

Cure::Cure(const Cure &copy) : AMateria(copy._type){}

Cure& Cure::operator=(const Cure &rhs)
{
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return (*this);
}

AMateria* Cure::clone() const
{
		return(new Cure);
}

