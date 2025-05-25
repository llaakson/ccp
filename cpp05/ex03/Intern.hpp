#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern &copy);
        Intern& operator=(const Intern &rhs);
        ~Intern();

		AForm* makeForm(std::string fname, std::string target);
        class NoForm : public std::exception {
			public:
				const char *what() const throw();
		};
};

#endif