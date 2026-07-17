/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 15:45:32 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/17 14:50:12 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
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
		std::cout << GREEN
				  << "\n[Form] "
				  << this->getName() 
				  << " signed.\n"
				  << RESET
				  << std::endl;
	}
	else
		throw(Form::GradeTooLowException());
}

std::ostream& operator<<(std::ostream& outputStream, const Form& form)
{
	outputStream << "\n[Form] Printing:\n" 
				 << "Name:\t\t\t\t" 
				 << form.getName()
				 << "\nSigned:\t\t\t\t" << (form.isFormSigned() ? "Signed" : "Not signed")
				 << "\nGrade required to sign:\t\t" << form.getGradeRequiredToSign()
				 << "\nGrade required to execute:\t" << form.getGradeRequiredToExecute()
				 << "\n"
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

