#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
	private:
		AMateria *_store[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &copy);
		MateriaSource& operator=(const MateriaSource &rhs);

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif