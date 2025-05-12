#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
	{
		_store[i] = nullptr;
	}
}

MateriaSource::~MateriaSource(){}
MateriaSource::MateriaSource(const MateriaSource &copy) : IMateriaSource(copy)
{}
MateriaSource& MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this !=  &rhs)
	{
		return (*this);
	}	
	return (*this);

}

void MateriaSource::learnMateria(AMateria* m) 
{
	for(int i = 0; i < 4; i++)
	{
		if (_store[i] == nullptr)
		{
			_store[i] = m;
			break;
		}
	}	
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < 4; i++)
	{
		if (_store[i]->getType() == type)
		{
			return (_store[i]);
		}
	}	
	return(_store[0]); // returns nullptr ????
}