#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
private:
    std::string target;
    RobotomyRequestForm();
    RobotomyRequestForm& operator= (const RobotomyRequestForm &obj);
public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &origin);
    virtual ~RobotomyRequestForm();
    virtual void execute(Bureaucrat const &executor) const;
};


#endif