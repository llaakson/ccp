#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm {
    private:
            std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &rhs);
        ~RobotomyRequestForm();

        void executeAction() const;
        std::string getTarget();
};

#endif