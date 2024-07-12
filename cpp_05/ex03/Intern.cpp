#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(Intern &origin)
{
    (void)origin;
}

Intern &Intern::operator=(const Intern &obj)
{
    if (this != &obj)
        return (*this);
    return (*this);
}

Intern::Intern() {}

Intern::~Intern() {}

const char *Intern::TypeNotMatchingException::what() const throw()
{
    return "This type isn't exist";
}

AForm *Intern::makeForm(std::string form, std::string target)
{
    AForm* aform;
    int i = -1;
    std::string arr[3] = {"presidential pardon", "robotomy request", "shrubberry creation"};

    for (i = 0; i < 3; i++){
        if (arr[i] == form)
            break ;
    }
    switch (i)
    {
        case 0:
            aform = new PresidentialPardonForm(target);
            break;
        case 1:
            aform = new RobotomyRequestForm(target);
            break;
        case 2:
            aform = new ShrubberyCreationForm(target);
            break;
        default:
            throw TypeNotMatchingException();
    }
    return aform;
}


