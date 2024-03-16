#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
        Bureaucrat& operator=(const Bureaucrat &obj);
        Bureaucrat();

    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &origin);
        ~Bureaucrat();
        void                incGrade();
        void                descGrade();
        int                 getGrade() const;
        const std::string&  getName() const;
        void                signForm(Form& f);

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