#include "Character.hpp"

Character::Character() : _name("Nameless")
{
	for(int i = 0; i < 4; i++)
	{
		slots[i] = nullptr;
	}
}

Character::~Character(){
	for(int i = 0; i < 4; i++)
	{
		if (slots[i] != nullptr)
		{
			delete (slots[i]);
		}
	}
}

Character::Character(const Character &copy)
{
	_name = copy._name;
	for(int i = 0; i < 4; i++)
	{
		slots[i] = copy.slots[i];
	}
}
Character& Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		for(int i = 0; i < 4; i++)
		{
			if (slots[i] != nullptr)
				delete slots[i];
			slots[i] = nullptr;
			if (rhs.slots[i] != nullptr)
				slots[i] = rhs.slots[i]->clone();
		}
	}
	return (*this);
}

Character::Character(std::string name) : _name(name)
{
	for(int i = 0; i < 4; i++)
	{
		slots[i] = nullptr;
	}
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
			return ;
		}
	}
	std::cout << "All slots are full." << std::endl;

}
void Character::unequip(int idx)
{
	if (slots[idx] != nullptr)
		slots[idx] = nullptr;
	else
		std::cout << "The slot " << idx << " is empty." << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (slots[idx] != nullptr) 
		slots[idx]->use(target);
}
