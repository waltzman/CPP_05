/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 15:45:32 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/17 11:00:15 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form()
{
	name = "Basic form";
	isSigned = false;
	gradeRequiredToSign = 150;
	gradeRequiredToExecute = 150;
	
	std::cout << "[Form] Constructor executed." << std::endl;
}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute)
{
	if (gradeToSign < Bureaucrat::highestGrade || gradeToExecute < Bureaucrat::highestGrade)
		throw (Form::GradeToHighException());
	if (gradeToSign > Bureaucrat::lowestGrade || gradeToExecute > Bureaucrat::lowestGrade)
		throw (Form::GradeToLowException());

	std::cout << "[Form] Parametrized constructor executed." << std::endl;
	this->name = name;
	isSigned = false;
	gradeRequiredToSign = gradeToSign;
	gradeRequiredToExecute = gradeToExecute;
}

Form::Form(const Form& other)
{
	name = other.name;
	isSigned = other.isSigned;
	gradeRequiredToSign = other.gradeRequiredToSign;
	gradeRequiredToExecute = other.gradeRequiredToExecute;
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

std::string const& Form::getName() const
{
	return (this->name);
}

bool Form::isFormSigned() const
{
	return (this->isSigned);
}

int Form::getGradeRequiredToSign() const
{
	return (this->gradeRequiredToSign);
}

int Form::getGradeRequiredToExecute() const
{
	return (this->gradeRequiredToExecute);
}

void	Form::beSigned(const Bureaucrat& b)
{
	if(b.getGradeRequiredToSign() <= this->gradeRequiredToSign)
	{
		this->isSigned = true;
		std::cout << "[Form]"
				  << b.getName() 
				  << "signed " 
				  << this->getName 
				  << " form.\n"
				  << std::endl;
	}
	else
		throw(Form::GradeTooLowException());
}

void	Form::beExecuted(const Bureaucrat& b)
{
	if(b.getGradeRequiredToExec() <= this->gradeRequiredToExec)
	{
		std::cout << "[Form]"
				  << b.getName() 
				  << "executed the " 
				  << this->getName 
				  << " form.\n"
				  << std::endl;
	}
	else
		throw(Form::GradeTooLowException());
}

std::ostream& operator<<(std::ostream outputStream, const Form& form)
{
	outputStream << "Form" << form.getName()
				 << "\nsigned:\t\t\t " << form.isSigned()
				 << "\nGrade required to sign:\t " << form.getGradeRequiredToSign()
				 << "\nGrade required to execute:\t " << form.getGradeRequiredToExec()
				 << std::endl;
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Form: grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Form: grade too high");
};

