#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
	{
		_store[i] = nullptr;
	}
}

MateriaSource::~MateriaSource(){
	for(int i = 0; i < 4; i++)
	{
		if (_store[i] != nullptr)
		{
			delete (_store[i]);
		}
	}
}

MateriaSource::MateriaSource(const MateriaSource &copy) : IMateriaSource(copy)
{
	for(int i = 0; i < 4; i++)
		{
			if (_store[i] != nullptr)
				delete _store[i];
			_store[i] = nullptr;
			if (copy._store[i] != nullptr)
				_store[i] = copy._store[i]->clone();
		}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != &rhs)
	{
		for(int i = 0; i < 4; i++)
		{
			if (_store[i] != nullptr)
				delete _store[i];
			_store[i] = nullptr;
			if (rhs._store[i] != nullptr)
				_store[i] = rhs._store[i]->clone();
		}
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
		if (_store[i] != nullptr && _store[i]->getType() == type)
		{
			return (_store[i]->clone());
		}
	}	
	return(0); 
}