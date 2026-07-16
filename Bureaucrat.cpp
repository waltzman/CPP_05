/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:01:09 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/16 10:14:36 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Buraaucrat::Bureaucrat()
{
	name = "Standart bureaucrat";
	grade = 150;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
{

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

}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat& Bureaucrat::operartor=(const Bureaucrat& other)
{
	if (this != &other) 
	{
		grade = other.grade;
		name = ohter.name;
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

void Bureaucrat::incrementGrade()
{
	incrementGrade(1);
}

void Bureaucrat::incrementGrade(int i)
{
	if (grade - i < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());
	else
		grade -= i;
}

void Bureaucrat::decrementGrade()

{
	decrementGrade(1);
}

void Bureaucrat::decrementGrade(int i)
{
	if (grade + 1 > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());
	else
		grade += i;
}

const char* Bureaucrat::GradeTooHighException::what() cosnt throw()
{
	return ("Bureaucrat: grasde too high");
}

const char* Bureaucrat::GradeTooLowException::what() cosnt throw()
{
	return ("Bureaucrat: grasde too low");
}

std::ostream& operator<<(std::stream& outputStream, const Bureaucrat& b)
{
	outputStream << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return (outputStream);
}








