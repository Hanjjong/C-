#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade > 150)
        throw GradeTooHighException();
    else if (grade < 1)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &origin) : _name(origin.getName()), _grade(origin.getGrade()) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj)
    {
        this->_grade = obj._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat(){}

void Bureaucrat::incGrade()
{
    if (this->_grade <= 1)
        throw GradeTooHighException();
    this->_grade -= 1;
}

void Bureaucrat::descGrade()
{
    if (this->_grade >= 150)
        throw GradeTooLowException();
    this->_grade += 1;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

const std::string &Bureaucrat::getName() const 
{
    return _name;
};

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "GradeTooHigh...";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "GradeTooLow...";
}
