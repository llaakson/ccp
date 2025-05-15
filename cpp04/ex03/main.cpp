#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <new>

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		std::cout << std::endl;
	}
	{
		std::cout << "----------------Bonus tests------------" << std::endl;
		Character Char_Chris("Chris");
		AMateria* bolt = new Ice();
		AMateria* medicine = new Cure();
		Char_Chris.equip(bolt);
		Char_Chris.equip(medicine);
		Character Char_BoB("Bob");
		std::cout << "Character Name: " << Char_BoB.getName() << std::endl;
		Character Char_Kevin("Kevin");
		// copy character -> Kevin should become Chris
		Char_Kevin = Char_Chris;		
		std::cout << "Characte Name: " << Char_Kevin.getName() << std::endl;

		// Bobs inventory is empty should not work
    	Char_BoB.use(0, Char_Chris);
		Char_BoB.use(1, Char_Chris);
		Char_BoB.use(5, Char_Chris);
		// Kevin has tow items 1 and 0 should work
		Char_Kevin.use(1, Char_Chris);
		Char_Kevin.use(0, Char_Chris);
		Char_Kevin.use(2, Char_Chris);
		Char_Kevin.use(4, Char_Chris);
		Char_Kevin.use(-5, Char_Chris);
		// FIll all slots
		AMateria* bolt1 = new Ice();
		AMateria* bolt2 = new Ice();
		AMateria* bolt3 = new Ice();
		Char_Kevin.equip(bolt1);
		Char_Kevin.equip(bolt2);
		Char_Kevin.equip(bolt3);
		// Kevin Inventory is full now
		Char_Kevin.use(1, Char_Chris);
		Char_Kevin.use(0, Char_Chris);
		Char_Kevin.use(2, Char_Chris);
		Char_Kevin.use(3, Char_Chris);
		Char_Kevin.use(4, Char_Chris);

		delete bolt3;

		std::cout << std::endl << std::endl;
	}
	{
		Character Char1("Player1");
		AMateria* brr = new Ice();
		AMateria* pomoc = new Cure();
		Char1.equip(brr);
		Char1.equip(pomoc);
		AMateria* fire = new Ice();
    	AMateria* lightning = new Cure();
    	Char1.equip(fire);
    	Char1.equip(lightning);
    	AMateria* iceToEquip = new Ice();
    	Char1.equip(iceToEquip); 
	
		Char1.use(0, Char1);
		Char1.use(1, Char1);
		Char1.unequip(0);
		std::cout << "Using unequipped Materia (should not work): " << std::endl;
		Char1.use(0, Char1);
		// try to unequip bs;
		Char1.unequip(-1);
		Char1.unequip(42);
		delete brr;
		delete iceToEquip;
		std::cout << std::endl;
	}
	{
		std::cout << "--learn and create materia--" << std::endl;
    	IMateriaSource* src = new MateriaSource();
    	src->learnMateria(new Ice());
    	src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());

    	AMateria* iceClone = src->createMateria("ice");
    	AMateria* cureClone = src->createMateria("cure");

		std::cout << iceClone->getType() << std::endl;
		std::cout << cureClone->getType() << std::endl;	

    	delete iceClone;
    	delete cureClone;
    	delete src;
	}
	return 0;
}
