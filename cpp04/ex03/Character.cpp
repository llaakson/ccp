#include "Character.hpp"

Character::Character()
{
	for(int i = 0; i < 4; i++)
	{
		slots[i] = nullptr;
	}
}
Character::~Character(){}
Character::Character(const Character &copy){
	*this = copy;
}
Character& Character::operator=(const Character &rhs){
	if (this != &rhs)
	{
		_name = rhs._name;
	}
	return (*this);
}

Character::Character(std::string name)
{
	_name = name;
}

// virtuals


std::string const & Character::getName() const
{
	return(_name);	
}
void Character::equip(AMateria* m)
{
	for(int i = 0; i < 4; i++)
	{
		if (slots[i] == nullptr)
		{
			slots[i] = m;
			break;
		}
	}

}
void Character::unequip(int idx)
{
	slots[idx] = nullptr;	
}

void Character::use(int idx, ICharacter& target)
{
	if (slots[idx] != nullptr) 
		slots[idx]->use(target);
}
