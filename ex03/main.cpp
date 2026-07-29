/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:03:10 by mcombeau          #+#    #+#             */
/*   Updated: 2026/07/29 12:58:45 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

#define RESET	"\e[0m"
#define RED		"\e[31m"

int	main(void)
{
	Bureaucrat	ceo("CEO", 1);

	Intern* intern = new Intern();
	
		AForm* shrubbery = intern->makeForm("ShrubberyCreationForm", "Forestry");
		AForm* robotomy = intern->makeForm("RobotomyRequestForm", "Zel");
		AForm* presidential = intern->makeForm("PresidentialPardonForm", "Eddy Snow");
	try
	{
		AForm* nonexistent = intern->makeForm("NonExistentForm", "target");
		(void) nonexistent;
	}

	catch(Intern::FormDoesNotExistException &e)
	{
		std::cout << RED
				  << "\n Exception: "
				  << e.what()
				  << RESET
				  << '\n';
	}
	
	std::cout << std::endl << "Three forms created by intern:\n"
			"\t" << *shrubbery << "\n"
			"\t" << *robotomy << "\n"
			"\t" << *presidential << std::endl;

	std::cout << "\n -------------  TEST: signing  forms ------------- \n" << std::endl;
 	
	// ERROR at signing form:
	try
	{
		shrubbery->beSigned(ceo);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		robotomy->beSigned(ceo);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
    // ERROR at signing form:
	try
	{
		presidential->beSigned(ceo);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	//std::cin.get();

	std::cout << "\n -------------  TEST: executing  forms ------------- \n" << std::endl;
	
	std::cout << std::endl << "Printing forms before executing:\n"
			"\t" << *shrubbery << "\n"
			"\t" << *robotomy << "\n"
			"\t" << *presidential << std::endl;
	
	// Erorrs executing forms
	try
	{
		shrubbery->execute(ceo);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		for (int i = 0; i < 10; ++i)
		robotomy->execute(ceo);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		presidential->execute(ceo);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	delete intern;
	delete shrubbery;
	delete robotomy;
	delete presidential;
	return (0);
}
