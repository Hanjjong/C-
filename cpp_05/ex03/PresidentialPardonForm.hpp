#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private:
    std::string target;
    PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm &obj);
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &origin);
    virtual ~PresidentialPardonForm();
    virtual void execute(Bureaucrat const &executor) const;
};

#endif