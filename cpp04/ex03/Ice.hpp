#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"

class Ice : public AMateria{
	public:
		Ice();
		~Ice();
		Ice(const Ice &copy);
		Ice& operator=(const Ice &rhs);

		AMateria* clone() const;
};

#endif