#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: AForm("RobotomyRequestForm", false, 72, 45), target(target){}

RobotomyRequestForm::RobotomyRequestForm() 
: AForm("", false, 72, 45){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    if(this != &obj)
    {
        this->target = obj.target;
    }
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &origin)
: AForm(origin.getName(), origin.getSign(), 72, 45), target(origin.target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
    if (!isSigned()) 
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade()) 
        throw AForm::GradeTooLowException();
    std::cout << "Bzzzz........." << std::endl;
    if (std::rand() % 2) 
        std::cout << target << " has been robotomized successfully." << std::endl;
    else 
        std::cout << "Robotomy failed on " << target << "." << std::endl;
}