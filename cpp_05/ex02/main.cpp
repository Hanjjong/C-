#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream &out, Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() + ",  bureaucrat grade" + std::to_string(bureaucrat.getGrade());
    return out;
}

int main()
{
    try
	{
		try
		{
			Bureaucrat test("test", 200);	
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		Bureaucrat a("A breaucrat", 150);
		Bureaucrat b("B breaucrat", 1);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;

		// a.descGrade();
		// b.descGrade();

		// std::cout << a << std::endl;
		// std::cout << b << std::endl;
		// std::cout << std::endl;

		a.incGrade();
		// b.incGrade();
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;


		try
		{
			Form	form("사직서", false, 100, 10);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		Form	form("사직서", false, 100, 10);
		a.signForm(form);
		

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}

