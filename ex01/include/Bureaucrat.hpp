/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:03:07 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/28 10:31:14 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

		const std::string& getName() const;
		int	getGrade() const;
		void incrementGrade(int i);
		void decrementGrade(int i);
		void signForm(Form& form);

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
