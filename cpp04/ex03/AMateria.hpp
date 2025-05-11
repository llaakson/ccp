
#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string const _type;
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria &copy);
        AMateria& operator=(const AMateria &rhs);
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
        ~AMateria();
};

#endif