/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 10:16:49 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/17 10:43:20 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
/* Create a form with grade too high */
std::cout << "\n******* EXCEPTION CREATING FORM *******\n\n";

	{
		try
		{
			Form form1("form 1", 0, 5);
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}

	std::cout << "\n******* CREATING FORM *******\n\n";


	{
		try
		{
			Bureaucrat b1("B 1", 15);
			Form form("form 33", 20, 45);
			b1.signForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << "\n******* BUREAUCRAT SIGNING FORM *******\n\n";


	/* Create form and sign it */
	{
		try
		{
			Bureaucrat b("B", 10);
			Form form("form 2026", 20, 45);
			
			b.signForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n******* EXCEPTION SIGNING FORM BY BUREAUCRAT *******\n\n";
	/* Create form and try to execute it but the grade is not enough */
	{
		try
		{
			Bureaucrat b("B", 35);
			Form form("form 2026", 20, 45);
			
			b.signForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n******* EXECUTING FORM BY UREAUCRAT *******\n\n";
	/* Create form and try to execute it but the grade is not enough */
	{
		try
		{
			Bureaucrat b("B", 35);
			Form form("form 2026", 20, 45);
			
			b.execForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);

	std::cout << "\n******* EXCEPTION EXECUTING FORM BY UREAUCRAT *******\n\n";
	/* Create form and try to execute it but the grade is not enough */
	{
		try
		{
			Bureaucrat b("B", 50);
			Form form("form 2026", 20, 45);
			
			b.execForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
