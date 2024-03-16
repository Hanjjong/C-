#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name(""), _sign(false), _signGrade(0), _execGrade(0){}

Form::Form(std::string name, bool sign, int signGrade, int execGrade) 
    : _name(name), _sign(sign), _signGrade(signGrade), _execGrade(execGrade)
{
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooHighException();
    else if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooLowException();
}

Form::Form(Form &origin) : _name(origin._name), _sign(origin._sign), _signGrade(origin._signGrade), _execGrade(origin._execGrade) {}

Form::~Form(){}

Form &Form::operator=(const Form &obj)
{
    return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "GradeTooHigh...";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "GradeTooLow...";
}

const std::string &Form::getName() const
{
   return _name;
}

bool Form::getSign() const
{
    return _sign;
}

int Form::getSignGrade() const
{
    return _signGrade;
}

int Form::getExecGrade() const
{
    return _execGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signGrade)
        throw GradeTooLowException();
    _sign = true;
}
