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
		try{
			return(new Cure);
		}
		catch (std::bad_alloc& e){ 
			std::cout << "Cure memory allocation failed " << std::endl;
			return nullptr;
		}
}

