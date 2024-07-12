#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>

class AForm;

class Intern
{
    public:
        Intern(Intern &origin);
        Intern& operator=(const Intern &obj);
        Intern();
        AForm* makeForm(std::string form, std::string target);
        ~Intern();

    class TypeNotMatchingException : public std::exception
    {
        public:
            const char *what() const throw();
    };
};

#endif