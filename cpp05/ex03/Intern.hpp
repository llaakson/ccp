#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern &copy);
        Intern& operator=(const Intern &rhs);
        ~Intern();

		Form* makeForm(std::string fname, std::string target);
};

#endif