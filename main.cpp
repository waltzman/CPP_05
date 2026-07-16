/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 10:16:49 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/16 12:55:18 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

#define RED "\033[31m"
#define RESET "\033[0m"

int main()
{
	std::cout << " \n -----  INSERTION OPERATOR << OVERLOAD TEST -----\n" << std::endl;
	Bureaucrat* bureaucrat = new Bureaucrat("Roman", 100);
	std::cout << std::endl;
	std::cout << "Insertion operator \"<<\"  overload test:\n"
			  << *bureaucrat;
	delete bureaucrat;
	
	try
	{
		std::cout << " \n -----  TESTING NOT DEFINED EXCEPTION  -----\n" << std::endl;
		Bureaucrat* bureaucrat = new Bureaucrat("Roman", 200);
		(void)bureaucrat;
	}
	
	catch (std::exception& e)
	{
		std::cout << "My not defined exception code\n";
	}
	
	try
	{
		std::cout << " \n -----  TESTING TOO LOW EXCEPTION  -----\n" << std::endl;
		std::cout << "Testing GradeTooLowException:" << std::endl;
		Bureaucrat* bureaucrat = new Bureaucrat("Ivan", 200);
		bureaucrat->getGrade();
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
		Bureaucrat* bureaucrat = new Bureaucrat("Ivan", 0);
		bureaucrat->getGrade();
	
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
	
	return (0);
}
