#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
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

void Bureaucrat::signForm(AForm& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << this->_name << " signs " << f.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->_name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try 
    {
        form.execute(*this); // 현재 객체를 전달하기 위해 *this 사용
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

