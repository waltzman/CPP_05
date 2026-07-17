/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:03:07 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/17 10:56:00 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Form.hpp"
#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
	private:
		std::string name;
		int grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

		const std::string& 	getName() const;
		int					getGrade() const;

		void incrementGrade(int i);
		void decrementGrade(int i);
		void signForm(Form& form);
		void execForm(Form& form);

		static int const	highestGrade = 1;
		static int const	lowestGrade = 150;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
			
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
