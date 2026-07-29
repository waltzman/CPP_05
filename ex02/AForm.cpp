/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 15:45:32 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/29 09:19:53 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class Bureaucrat;

AForm::AForm(): name("Basic form"), isSigned(false), gradeRequiredToSign(150), gradeRequiredToExecute (150)
{	
	std::cout << "[AForm] Default constructor executed." << std::endl;
}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute) :
		name(name), isSigned(false), 
		gradeRequiredToSign(gradeToSign), 
		gradeRequiredToExecute (gradeToExecute)
{
	if (gradeRequiredToSign < Bureaucrat::highestGrade || gradeRequiredToExecute < Bureaucrat::highestGrade)
		throw (AForm::GradeTooHighException());
	if (gradeRequiredToSign > Bureaucrat::lowestGrade || gradeRequiredToExecute > Bureaucrat::lowestGrade)
		throw (AForm::GradeTooLowException());

	std::cout << "[AForm] Parametrized constructor called." << std::endl;
}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute, const std::string& target) :
		name(name), isSigned(false), 
		gradeRequiredToSign(gradeToSign), 
		gradeRequiredToExecute (gradeToExecute),
		target(target)
{
	if (gradeRequiredToSign < Bureaucrat::highestGrade || gradeRequiredToExecute < Bureaucrat::highestGrade)
		throw (AForm::GradeTooHighException());
	if (gradeRequiredToSign > Bureaucrat::lowestGrade || gradeRequiredToExecute > Bureaucrat::lowestGrade)
		throw (AForm::GradeTooLowException());

	std::cout << "[AForm] Parametrized constructor called." << std::endl;
}

AForm::AForm(const AForm& other) :
	name(other.name), isSigned(other.isSigned), 
	gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute (other.gradeRequiredToExecute)
{
	(void)other;
	std::cout << "[AForm] Copy constructor called." << std::endl;
}

AForm::~AForm()
{
	std::cout << "[AForm] Destructor called." << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	(void)other;
	std::cout << "[AForm] Copy assignment operator called." << std::endl;
	return (*this);
}

const std::string& AForm::getName() const
{
	return (this->name);
}

const std::string& AForm::getTarget() const
{
	return target;
}


bool AForm::isFormSigned() const
{
	return (this->isSigned);
}

int AForm::getGradeRequiredToSign() const
{
	return (this->gradeRequiredToSign);
}

int AForm::getGradeRequiredToExecute() const
{
	return (this->gradeRequiredToExecute);
}

void AForm::beSigned(const Bureaucrat& b)
{
	if(b.getGrade() <= this->gradeRequiredToSign)
		this->isSigned = true;
	else
		throw(GradeTooLowException());
}

void		AForm::execute(const Bureaucrat& executor) const
{
	if (!isSigned)
		throw FormNotSignedException();
	if (gradeRequiredToExecute < executor.getGrade())
		throw GradeTooLowException();
	executeFormAction();
}
std::ostream& operator<<(std::ostream& outputStream, const AForm& Aform)
{
	outputStream << "\n[Form] Printing:\n" 
				 << "Name:\t\t\t\t" 
				 << Aform.getName()
				 << "\nSigned:\t\t\t\t" << (Aform.isFormSigned() ? "Signed" : "Not signed")
				 << "\nGrade required to sign:\t\t" << Aform.getGradeRequiredToSign()
				 << "\nGrade required to execute:\t" << Aform.getGradeRequiredToExecute()
				 << "\n"
				 << std::endl;
	return outputStream;
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return ("Exception: AForm: grade too low");
};

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return ("Exception: AForm: grade too high");
};

const char* AForm::FormNotSignedException::what(void) const throw()
{
	return ("Exception: Form: not signed");
};

