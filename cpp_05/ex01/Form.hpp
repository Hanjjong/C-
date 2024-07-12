#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _sign;
        const int           _signGrade;
        const int           _execGrade;
        Form();
        Form& operator=(const Form &obj);

    public:
        Form(std::string name, bool sign, int signGrade, int execGrade);
        Form(Form& origin);
        ~Form();
        const std::string&  getName() const;
        bool                getSign() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;
        void                beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception
    {    
        public:
            const char *what() const throw();
    };    

    class GradeTooLowException : public std::exception
    {    
        public:
            const char *what() const throw();
    };   
};

#endif