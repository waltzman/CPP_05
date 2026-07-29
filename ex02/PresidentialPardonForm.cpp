/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:07:25 by mcombeau          #+#    #+#             */
/*   Updated: 2026/07/28 16:58:57 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm():
	AForm("Presidential Pardon Form", 25, 5, "undefined")
{
	std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & other):
	AForm(other), target(other.target)
{
	std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target):
	AForm("Presidential Pardon Form", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm attribute constructor called." << std::endl;
	if (target.empty())
		this->target = "undefined";
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
	return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
									PresidentialPardonForm const & other)
{
	this->target = other.target;
	return (*this);
}

std::string const &	PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

void	PresidentialPardonForm::executeFormAction () const
{
	std::cout << target
			  << " has been pardoned by Zaphod Beeblebrox." 
			  << std::endl;
	return ;
}
