#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter{
	private:
		std::string _name;
		AMateria *slots[4];
	public:
		Character();
		~Character();
		Character(std::string name);
		Character(const Character &copy);
		Character& operator=(const Character &rhs);

		std::string const & getName() const override;
    	void equip(AMateria* m) override;
    	void unequip(int idx) override;
    	void use(int idx, ICharacter& target) override;
};

#endif