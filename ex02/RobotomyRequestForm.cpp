/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:05:44 by mcombeau          #+#    #+#             */
/*   Updated: 2026/07/29 10:34:34 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

RobotomyRequestForm::RobotomyRequestForm()
		: AForm("Robotomy Request Form", 72, 45, "undefined")
{
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & other)
		:AForm(other),
		target(other.target)
{
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
		: AForm("Robotomy Request Form", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm parametrized constructor called." << std::endl;
	if (target.empty())
		this->target = "undefined";
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
	return ;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & other)
{
	this->target = other.target;
	return (*this);
}

std::string const &	RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}
 
void	RobotomyRequestForm::executeFormAction() const
{
	std::cout << "* ... drilling noises .... sshpshshzzzz.... *" << std::endl;
	if (std::rand() % 2)
		std::cout << target
				  << GREEN
				  << " successfully robotomized!"
				  << RESET
				  << std::endl;
	else
		std::cout << target
				  << BLUE
				  << " robotomy failed"
				  << RESET
				  << std::endl;
	return ;
}
