#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form
{
    private:
        const std::string _name;
        bool      _sign;
        const int _signGrade;
        const int _execGrade;

    public:
        Form();
        ~Form();
        void    beSigned();
        void    signForm();

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