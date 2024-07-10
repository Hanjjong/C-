#ifndef SHRUBBERYCREATION_HPP
#define SHRUBBERYCREATION_HPP

#include "AForm.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;
    ShrubberyCreationForm();
    ShrubberyCreationForm& operator= (const ShrubberyCreationForm &obj);
public:
    ShrubberyCreationForm(std::string target); 
    ShrubberyCreationForm(const ShrubberyCreationForm &origin);
    virtual ~ShrubberyCreationForm();
    void execute(Bureaucrat const &executor) const;
};

#endif