/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 10:16:49 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/28 10:03:26 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

#define RED "\033[31m"
#define RESET "\033[0m"

int main()
{
	{
		std::cout << " \n -----  INSERTION OPERATOR << OVERLOAD TEST -----\n" << std::endl;
		Bureaucrat bureaucrat("Roman", 100);
		std::cout << std::endl;
		std::cout << "Insertion operator \"<<\"  overload test:\n"
				  << bureaucrat
				  << std::endl;
	}
	
	try
	{
		std::cout << " \n -----  TESTING CUSTOM EXCEPTION  -----\n" << std::endl;
		Bureaucrat* bureaucrat = new Bureaucrat("Roman", 200);
		(void)bureaucrat;
	}
	
	catch (std::exception& e)
	{
		std::cout << "Exception:"
				  << std::endl
				  << RED
				  << "Custom defined exception code"
				  << RESET
				  << std::endl;
	}
	
	try
	{
		std::cout << " \n -----  TESTING TOO LOW EXCEPTION  -----\n" << std::endl;
		std::cout << "Testing GradeTooLowException:" << std::endl;
		Bureaucrat bureaucrat("Ivan", 200);
		bureaucrat.getGrade();
	}
	
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << " \nFailed on Bureaucrat construction\n"
				  << "Exception:"
				  << std::endl
				  << RED
				  << e.what()
				  << RESET
				  << "\n";
	}

	try
	{
		std::cout << " \n -----  TESTING TOO HIGH EXCEPTION  -----\n" << std::endl;
		std::cout << "Testing GradeTooHighException:" << std::endl;
		Bureaucrat bureaucrat("Ivan", 0);
		bureaucrat.getGrade();
	
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{

		std::cout << "\nFailed on Bureaucrat construction\n"
				  << "Exception:"
				  << std::endl
				  << RED
				  << e.what()
				  << RESET
				  << "\n"
				  << std::endl;
	}

	try
	{
		std::cout <<  "\n -----  TESTING INCREMENT ----- \n"
				  << std::endl;
		Bureaucrat a("Zel", 100);
		std::cout << std::endl;
		std::cout << a;
		std::cout << std::endl;
		a.incrementGrade(10);
		std::cout << a;
		std::cout << std::endl;
		a.incrementGrade(20);
		std::cout << a;
		std::cout << std::endl;
		a.incrementGrade(200);
		std::cout << a;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		std::cout <<  "\n -----  TESTING DECREMENT ----- \n"
				  << std::endl;
		Bureaucrat b("Dan", 100);
		std::cout << std::endl;
		std::cout << b;
		std::cout << std::endl;
		b.decrementGrade(10);
		std::cout << b;
		std::cout << std::endl;
		b.decrementGrade(20);
		std::cout << b;
		std::cout << std::endl;
		b.decrementGrade(200);
		std::cout << b;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
	
	
	return (0);
}
