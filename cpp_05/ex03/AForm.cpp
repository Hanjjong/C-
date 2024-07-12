#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name(""), _sign(false), _signGrade(0), _execGrade(0){}

AForm::AForm(std::string name, bool sign, int signGrade, int execGrade) 
    : _name(name), _sign(sign), _signGrade(signGrade), _execGrade(execGrade)
{
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooHighException();
    else if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooLowException();
}

AForm::AForm(AForm &origin) : _name(origin._name), _sign(origin._sign), _signGrade(origin._signGrade), _execGrade(origin._execGrade) {}

AForm::~AForm(){}

AForm &AForm::operator=(const AForm &obj)
{
    if (this != &obj)
    {
        this->_sign = obj._sign;
    }
    return *this;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "GradeTooHigh...";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "FormNotSigned...";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "GradeTooLow...";
}

const std::string &AForm::getName() const
{
   return _name;
}

bool AForm::getSign() const
{
    return _sign;
}

int AForm::getSignGrade() const
{
    return _signGrade;
}

int AForm::getExecGrade() const
{
    return _execGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signGrade)
        throw GradeTooLowException();
    _sign = true;
}

bool AForm::isSigned() const 
{
    return _sign;
}
