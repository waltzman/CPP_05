/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:34:44 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/29 12:44:17 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTER_HPP
#define INTER_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

class Intern {
	private:
		AForm *newPresidentialPardon(std::string trg);
		AForm *newRobotomiRequest(std::string trg);
		AForm *newShrubberyCreation(std::string trg);
		static AForm *(Intern::*f[3])(std::string trg);
	public:
		Intern();
		~Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);
		AForm *makeForm(std::string name, std::string trg);

		class FormDoesNotExistException: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
};

#endif