#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
: AForm("", false, 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
: AForm("ShrubberyCreationForm", false, 145, 137), target(target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &origin)
: AForm(origin.getName(), origin.getSign(), 145, 137), target(origin.target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    if(this != &obj)
    {
        this->target = obj.target;
    }
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    std::ofstream file(target + "_shrubbery");
    if (file.is_open()) 
    {
        file << "     ccee88oo\n";
        file << "  C8O8O8Q8PoOb o8oo\n";
        file << " dOB69QO8PdUOpugoO9bD\n";
        file << "CgggbU8OU qOp qOdoUOdcb\n";
        file << "    6OuU  /p u gcoUodpP\n";
        file << "      \\\\//  /douUP\n";
        file << "        \\\\////\n";
        file << "         |||/\\\n";
        file << "         |||\\/\n";
        file << "         |||||\n";
        file << "   .....//||||....\n";
        file.close();
    } else {
        std::cout << "file open Error" << std::endl;
    }
}