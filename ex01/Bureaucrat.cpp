/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:01:09 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/16 14:31:19 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	name = "Standart bureaucrat";
	grade = 150;

	std::cout << "[Bureaucrat] default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
{

	std::cout << "[Bureaucrat] Parametrized constructor called" << std::endl;
	if (grade < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->grade = grade;
	this->name =name;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
			:name(other.name), grade(other.grade)
{
	std::cout << "[Bureaucrat] Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "[Bureaucrat] assignment operator called" << std::endl;
	if (this != &other) 
	{
		grade = other.grade;
		name = other.name;
	}
	return *this;
}

const std::string& Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}


void Bureaucrat::incrementGrade(int i)
{
	if (grade - i < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());
	else
		grade -= i;
}

void Bureaucrat::decrementGrade(int i)
{
	if (grade + i > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());
	else
		grade += i;
}



const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: grade too low");
}

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& b)
{
	outputStream << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return (outputStream);
}





