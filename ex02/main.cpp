/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:03:10 by mcombeau          #+#    #+#             */
/*   Updated: 2026/07/28 17:11:26 by rlobun           ###   ########.fr       */
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
	Bureaucrat	clerk("Clerk", 142);
	Bureaucrat	manager("Manager", 65);
	Bureaucrat	ceo("CEO", 1);

	std::cout << std::endl << "Three bureaucrats created:\n\n"
			"\t" << clerk << "\n"
			"\t" << manager << "\n"
			"\t" << ceo << std::endl << std::endl;
	
	AForm* shrubberyCeationForm = new ShrubberyCreationForm("Forest");
	AForm* robotomyRequestForm = new RobotomyRequestForm("CEO");
	AForm* presidentialPardonForm = new	PresidentialPardonForm("Aranceles");

	std::cout << std::endl << "Three forms created:\n"
			"\t" << *shrubberyCeationForm << "\n"
			"\t" << *robotomyRequestForm << "\n"
			"\t" << *presidentialPardonForm << std::endl;

	/*  std::cout << std::endl << "-- Signing and executing Shrubbery form:" << std::endl;
	lowlyBureaucrat.signForm(shrubForm);
	lowlyBureaucrat.executeForm(shrubForm);
	averageBureaucrat.executeForm(shrubForm);

	std::cout << std::endl << "-- Signing and executing Presidential Pardon form:" << std::endl;
	highBureaucrat.executeForm(pardonForm);
	highBureaucrat.signForm(pardonForm);
	highBureaucrat.executeForm(pardonForm);
	highBureaucrat.incrementGrade();
	highBureaucrat.executeForm(pardonForm);

	std::cout << std::endl << "-- Signing and executing Robotomy form:" << std::endl;
	averageBureaucrat.executeForm(robotomyForm);
	averageBureaucrat.signForm(robotomyForm);
	averageBureaucrat.executeForm(robotomyForm);
	highBureaucrat.executeForm(robotomyForm); */

	std::cout << std::endl;
	return (0);
}
