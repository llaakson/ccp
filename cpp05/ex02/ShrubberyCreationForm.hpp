#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    private:
            int i;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs);
        ~ShrubberyCreationForm();

        void executeAction() const;

    class ShrubberyException : public std::exception {
		public:
			const char *what() const throw();
	};

};



#endif