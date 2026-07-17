/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 15:45:32 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/17 11:56:36 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

#define RED "\033[31m"
#define RESET "\033[0m"

Form::Form(): name("Basic formn"), isSigned(false), gradeRequiredToSign(150), gradeRequiredToExecute (150)
{	
	std::cout << "[Form] Constructor executed." << std::endl;
}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute) :
		name(name), isSigned(false), gradeRequiredToSign(gradeToSign), gradeRequiredToExecute (gradeToExecute)
{
	if (gradeRequiredToSign < Bureaucrat::highestGrade || gradeRequiredToExecute < Bureaucrat::highestGrade)
		throw (Form::GradeTooHighException());
	if (gradeRequiredToSign > Bureaucrat::lowestGrade || gradeRequiredToExecute > Bureaucrat::lowestGrade)
		throw (Form::GradeTooLowException());

	std::cout << "[Form] Parametrized constructor executed." << std::endl;
}

Form::Form(const Form& other) :
	name(other.name), isSigned(other.isSigned), 
	gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute (other.gradeRequiredToExecute)
{
	(void)other;
	std::cout << "[Form] Copy constructor executed." << std::endl;
}

Form::~Form()
{
	std::cout << "[Form] Destructor executed." << std::endl;
}

Form& Form::operator=(const Form& other)
{
	(void)other;
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
	if(b.getGrade() <= this->gradeRequiredToSign)
	{
		this->isSigned = true;
		std::cout << "\n[Form] "
				  << this->getName() 
				  << " signed.\n"
				  << std::endl;
	}
	else
		throw(Form::GradeTooLowException());
}

void	Form::beExecuted(const Bureaucrat& b) const
{
	if(b.getGrade() <= this->gradeRequiredToExecute)
	{
		std::cout << "[Form] Bureaucrat "
				  << this->getName() 
				  << " executed.\n"
				  << std::endl;
	}
	else
		throw(Form::GradeTooLowException());
}

std::ostream& operator<<(std::ostream& outputStream, const Form& form)
{
	outputStream << "Form" << form.getName()
				 << "\nsigned:\t\t\t " << form.isFormSigned()
				 << "\nGrade required to sign:\t " << form.getGradeRequiredToSign()
				 << "\nGrade required to execute:\t " << form.getGradeRequiredToExecute()
				 << std::endl;
	return outputStream;
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("Exception: Form: grade too low");
};

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("Exception: Form: grade too high");
};

