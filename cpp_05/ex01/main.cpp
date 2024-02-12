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

		Bureaucrat a("a", 150);
		Bureaucrat b("b", 1);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;

		// a.descGrade();
		// b.descGrade();

		// std::cout << a << std::endl;
		// std::cout << b << std::endl;
		// std::cout << std::endl;

		a.incGrade();
		b.incGrade();
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}

