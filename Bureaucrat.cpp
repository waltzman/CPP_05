/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:01:09 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/15 07:18:31 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Buraaucrat::Bureaucrat()
{
	name = "Standart bureaucrat";
	grade = 150;
}

Bureaucrat::Bureaucrat(const std::strig& name, int grade)
{
	if (grade < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->grade = grade;
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

void Bureaucrat::incrementGradde()
{
	incrementGrade(1);
}

void Bureaucrat::incrementGrade(int i)
{
	if (grade-1 < Bureaucrat::highest
