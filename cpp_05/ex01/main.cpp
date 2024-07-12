#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream &out, Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() + ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}

std::ostream& operator<<(std::ostream &out, Form &form)
{
	out << "Form : " + form.getName();
	out << " Signed : " << form.getSign(); 
	out << " SignGrade : " << form.getSignGrade();
	out << "ExecGrade : " << form.getExecGrade();
	return out;
}

int main()
{
    try
	{
		try
		{
			Form form("사직서", false, 200, -1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		Bureaucrat a("A breaucrat", 150);
		Bureaucrat b("B breaucrat", 1);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;

		
		Form form("사직서", false, 100, 10);
		a.signForm(form);
		b.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

