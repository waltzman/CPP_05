/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:36:46 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/29 12:57:59 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"

static const std::string formsNames[3] = 
	{"PresidentialPardonForm", "RobotomyRequestForm" ,"ShrubberyCreationForm"};

AForm *(Intern::*Intern::f[3])(std::string) = 
	{&Intern::newPresidentialPardon, &Intern::newRobotomiRequest, &Intern::newShrubberyCreation};

AForm *Intern::newPresidentialPardon(std::string trg) {
	return (new PresidentialPardonForm(trg));
}

AForm *Intern::newRobotomiRequest(std::string trg){
	return (new RobotomyRequestForm(trg));
}

AForm *Intern::newShrubberyCreation(std::string trg){
	return (new ShrubberyCreationForm(trg));
}

Intern::Intern() {
	std::cout << "[Intern] constructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << "[Intern] destructor called" << std::endl;

}

Intern::Intern(const Intern &src) {
	std::cout << "[Intern] copy constructor called" << std::endl;
	*this = src;
}

Intern &Intern::operator=(const Intern &src) {
	std::cout << "[Intern] Copy assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string trg) {
	int i = 0;

	while (i < 3)
	{
		if (formsNames[i] == name)
		{
			std::cout << "Intern creates "
					  << name 
					  << std::endl;
			return (this->*f[i])(trg);
		}
		i++;	
	}
	if (i == 3) 
		throw Intern::FormDoesNotExistException();
	return (NULL);
}

const char* Intern::FormDoesNotExistException::what() const throw()
{
	return ("[Intern]: type of form does not exist");
}