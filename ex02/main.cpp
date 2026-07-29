/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:03:10 by mcombeau          #+#    #+#             */
/*   Updated: 2026/07/29 11:28:37 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

#define RESET	"\e[0m"
#define RED		"\e[31m"

int	main(void)
{
	Bureaucrat	intern("Intern", 149);
	Bureaucrat	clerk("Clerk", 136);
	Bureaucrat	manager("Manager", 44);
	Bureaucrat	ceo("CEO", 1);

	std::cout << std::endl << "Three bureaucrats created:\n\n"
			"\t" << intern << "\n"
			"\t" << clerk << "\n"
			"\t" << manager << "\n"
			"\t" << ceo << std::endl << std::endl;
	
	AForm* shrubberyCeationForm = new ShrubberyCreationForm("Forest");
	AForm* robotomyRequestForm = new RobotomyRequestForm("Zel");
	AForm* presidentialPardonForm = new	PresidentialPardonForm("Edward Snow");

	std::cout << std::endl << "Three forms created:\n"
			"\t" << *shrubberyCeationForm << "\n"
			"\t" << *robotomyRequestForm << "\n"
			"\t" << *presidentialPardonForm << std::endl;

	std::cout << "\n -------------  TEST: executing not signed forms ------------- \n" << std::endl;

	try
	{
		shrubberyCeationForm->execute(intern);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << '\n';
	}
	try
	{
		shrubberyCeationForm->execute(clerk);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << '\n';
	}

	try
	{
		shrubberyCeationForm->execute(manager);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << '\n';
	}

	try
	{
		shrubberyCeationForm->execute(ceo);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << '\n';
	}

	//std::cin.get();

	std::cout << "\n -------------  TEST: signing  forms ------------- \n" << std::endl;
 	
	// ERROR at signing form:
	try
	{
		shrubberyCeationForm->beSigned(intern);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		shrubberyCeationForm->beSigned(clerk);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		robotomyRequestForm->beSigned(manager);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
    // ERROR at signing form:
	try
	{
		presidentialPardonForm->beSigned(manager);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		presidentialPardonForm->beSigned(ceo);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	//std::cin.get();

	std::cout << "\n -------------  TEST: executing  forms ------------- \n" << std::endl;
	
	std::cout << std::endl << "Printing forms before executing:\n"
			"\t" << *shrubberyCeationForm << "\n"
			"\t" << *robotomyRequestForm << "\n"
			"\t" << *presidentialPardonForm << std::endl;
	
	// Erorrs executing forms
	try
	{
		shrubberyCeationForm->execute(intern);
	}
	catch(const std::exception& e)
	{
		std::cout << "Intern failed execute the form." << std::endl;
		std::cout << e.what() << '\n';
	}

	try
	{
		robotomyRequestForm->execute(clerk);
	}
	catch(const std::exception& e)
	{
		std::cout << "Clerk failed execute the form." << std::endl;
		std::cout << e.what() << '\n';
	}

	try
	{
		presidentialPardonForm->execute(manager);
	}
	catch(const std::exception& e)
	{
		std::cout << "Manager failed execute the form." << std::endl;
		std::cout << e.what() << '\n';
	}
	// Clerk executing all possible forms
	shrubberyCeationForm->execute(clerk);
	//std::cin.get();
	// Manager executing all possible forms
	shrubberyCeationForm->execute(manager);
	for (int i = 0; i < 10; ++i)
		robotomyRequestForm->execute(manager);

	// CEO executing all possible forms
	
	shrubberyCeationForm->execute(ceo);
	//std::cin.get();

	for (int i = 0; i < 10; ++i)
		robotomyRequestForm->execute(ceo);
	presidentialPardonForm->execute(ceo);
	
	delete shrubberyCeationForm;
	delete robotomyRequestForm;
	delete presidentialPardonForm;
	return (0);
}
