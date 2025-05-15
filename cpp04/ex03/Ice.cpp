#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice(){}

Ice::Ice(const Ice &copy) : AMateria(copy._type){}

Ice& Ice::operator=(const Ice &rhs){
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return (*this);
}

AMateria* Ice::clone() const
{	
	try{
		return(new Ice);
	}
	catch (std::bad_alloc& e){
		std::cout << "Ice memory allocation failed " << std::endl;
		return nullptr;
	}
}