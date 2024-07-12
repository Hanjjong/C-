#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

std::ostream& operator<<(std::ostream &out, Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() + ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}

std::ostream& operator<<(std::ostream &out, AForm &form)
{
	out << "Form : " + form.getName();
	out << " Signed : " << form.getSign(); 
	out << " SignGrade : " << form.getSignGrade();
	out << " ExecGrade : " << form.getExecGrade();
	return out;
}

int main() {
    try {
        Bureaucrat john("John", 1); // 높은 등급의 Bureaucrat
        Bureaucrat mike("Mike", 150); // 낮은 등급의 Bureaucrat

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("robot");
        PresidentialPardonForm pardon("criminal");

        // ShrubberyCreationForm 테스트
        std::cout << "Testing ShrubberyCreationForm:" << std::endl;
        john.signForm(shrubbery);
        john.executeForm(shrubbery);
        std::cout << std::endl;

        // RobotomyRequestForm 테스트
        std::cout << "Testing RobotomyRequestForm:" << std::endl;
        john.signForm(robotomy);
        john.executeForm(robotomy);
        std::cout << std::endl;

        // PresidentialPardonForm 테스트
        std::cout << "Testing PresidentialPardonForm:" << std::endl;
        // john.signForm(pardon);
        john.executeForm(pardon);
        std::cout << std::endl;

        // 낮은 등급 Bureaucrat 테스트
        std::cout << "Testing with low grade Bureaucrat:" << std::endl;
        mike.signForm(shrubbery); // 서명 실패 예상
        mike.executeForm(shrubbery); // 실행 실패 예상
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
