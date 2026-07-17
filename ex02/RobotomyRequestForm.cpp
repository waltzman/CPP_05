/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:05:44 by mcombeau          #+#    #+#             */
/*   Updated: 2026/07/17 15:52:26 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

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

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	std::cout << "* ... drilling noises .... sshpshshzzzz.... *" << std::endl;
	if (std::rand() % 2)
		std::cout << this->target 
				  << " successfully robotomized!"
				  << std::endl;
	else
		std::cout << this->target
				  << " robotomy failed"
				  << std::endl;
	return ;
}
