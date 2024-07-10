#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
: AForm("PresidentialPardonForm", false, 25, 5), target(target){}

PresidentialPardonForm::PresidentialPardonForm() 
: AForm("", false, 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &origin)
: AForm(origin.getName(), origin.getSign(), 25, 5), target(origin.target){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm &obj)
{
    if(this != &obj)
    {
        this->target = obj.target;
    }
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned()) 
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade()) 
        throw AForm::GradeTooLowException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
