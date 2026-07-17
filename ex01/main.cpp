/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 10:16:49 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/17 14:42:39 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RED "\033[31m"
#define RESET "\033[0m"

int main()
{
	std::cout << "\n******* EXCEPTION CREATING FORM *******\n\n";

	{
		try
		{
			Form form1("form1", 0, 5);
		}
		catch(std::exception &e)
		{
			std::cout << RED 
					  << e.what() 
					  << RESET
					  << std::endl;
		}
		
	}
	
	std::cout << "\n******* BUREAUCRAT SIGNING FORM *******\n\n";

	{
		try
		{
			Bureaucrat b("B", 10);
			Form form("form 2026", 20, 45);
			
			b.signForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << RED
					  << e.what() 
					  << RESET
					  << std::endl;
		}
	}

	std::cout << "\n******* EXCEPTION SIGNING FORM BY BUREAUCRAT *******\n\n";

	{
		try
		{
			Bureaucrat b("B", 35);
			Form form("form 2026", 20, 45);
			
			b.signForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << RED
					  << e.what() 
					  << RESET
					  << std::endl;
		}
	}
std::cout << "\n******* FORM INSERTION OPERATOR OVERLOAD TEST *******\n\n";
	{
		try
		{
			Form form("form2026", 100, 100);
			
			std::cout << form;
		}
		catch (std::exception &e)
		{
			std::cout << RED
					  << e.what() 
					  << RESET
					  << std::endl;
		}
	}
	return (0);
}
