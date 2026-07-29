/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 07:01:09 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/29 09:35:51 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

Bureaucrat::Bureaucrat() : name("Bored bureaucrat") , grade(150)
{
	std::cout << "[Bureaucrat] default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& new_name, int new_grade) : 
	name(new_name), grade(new_grade)
{
	std::cout << "[Bureaucrat] Parametrized constructor called" << std::endl;
	if (new_grade < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());
	else if (new_grade > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	name(other.name), grade(other.grade)
{
	std::cout << "[Bureaucrat] Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] "
			  << name
			  << " destructor called\n" 
			  << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "[Bureaucrat] Copy assignment operator called" << std::endl;
	if (this != &other) 
		grade = other.grade;
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
	else if (grade - i > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());
	else
		grade -= i;
}

void Bureaucrat::decrementGrade(int i)
{
	if (grade + i > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());
	else if (grade + i < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());
	else
		grade += i;
}

void Bureaucrat::signForm(AForm& f)
{
	try
	{
		f.beSigned(*this);
		std::cout <<  "[Bureaucrat] "
				  << name 
				  << " signed the " 
				  << f.getName() << " form.\n" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "\n[Bureaucrat] "
				  << name
				  << " could not sign the "
				  << f.getName()
				  << " form because: \n"
				  << RED
				  << e.what()
				  << std::endl
				  << RESET
				  << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout <<  "[Bureaucrat] "
				  << name 
				  << " executed the " 
				  << form.getName() << " form.\n" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "[Bureaucrat] "
				  << name
				  << " could not execute the "
				  << form.getName()
				  << " form, because \n"
				  << RED
				  << e.what()
				  << RESET
				  << "\n"
				  << std::endl;
	}
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





