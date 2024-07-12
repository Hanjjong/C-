#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _sign;
        const int           _signGrade;
        const int           _execGrade;
        AForm();
        AForm& operator=(const AForm &obj);

    public:
        AForm(std::string name, bool sign, int signGrade, int execGrade);
        AForm(AForm& origin);
        virtual ~AForm();
        const std::string&  getName() const;
        bool                getSign() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;
        bool                isSigned() const;
        void                beSigned(const Bureaucrat& bureaucrat);
        virtual void        execute(Bureaucrat const &executor) const = 0;

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
    class FormNotSignedException : public std::exception
    {    
        public:
            const char *what() const throw();
    }; 
};

// std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif