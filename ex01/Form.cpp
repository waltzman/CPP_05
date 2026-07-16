/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 15:45:32 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/16 16:30:34 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form()
{
	name = "Basic form";
	isSigned = false;
	gradeRequiredToSign(Bureaucrat::lowestGrade);
	gradeRequiredToExecute(Bureaucrat::lowestGrade);
	
	std::cout << "[Form] Constructor executed." << std::endl;
}

Form::Form(const std::string& name, cosnt int gradeToSign, const int gradeToExecute)
{
	if (gradeToSign < Bureaucrat::highestGrade || gradeToExecute < Bureaucrat::highestGrade)
		throw (Form::GradeToHighException());
	if (gradeToSign > Bureaucrat::lowestGrade || gradeToExecute > Bureaucrat::lowestGrade)
		throw (Form::GradeToLowException());

	std::cout << "[Form] Parametrized constructor executed." << std::endl;
	this->name = name;
	isSigned = false;
	gradeRequiredToSign(gradeToSign);
	gradeRequiredToExecute(gradeToExecute);
}

Form::Form(const Form& other)
{
	name = other.name;
	isSigned = other.isSigned;
	gradeRequiredToSign = other.gradeRequiredToSign;
	graseRequiredToExecute = other.gradeRequiredToExecute;
	std::cout << "[Form] Copy constructor executed." << std::endl;
}

Form::~Form()
{
	std::cout << "[Form] Destructor executed." << std::endl;
}

Form& From::operator=(const Form& other)
{
	name = other.name;
	isSigned = other.isSigned;
	gradeRequiredToSign = other.gradeRequiredToSign;
	graseRequiredToExecute = other.gradeRequiredToExecute;
	std::cout << "[Form] Assignment operator executed." << std::endl;
	return (*this);
}

std::string cosnt& Form::getName() const
{
	return (this->name);
}

bool Form::isSigned() const
{
	return (this->isSigned);
}

int Form::getGradeRequiredToSign() cosnt
{
	return (this->gradeRequiredToSign);
}

int Form::getGradeRequiredToExecute() cosnt
{
	return (this->gradeRequiredToExecute);
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (this->isSigned)
		std::cout << "[Form] the form is already signed"
	else
	{
		if(b.getGradeRequiredToSign() <= this->gradeRequiredToSign)
			this->isSigned = true;
		else
			throw(Form::GradeTooLowException());
	}
}