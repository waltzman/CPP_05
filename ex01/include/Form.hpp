/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:21:16 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/17 07:38:38 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		std::string const	name;
		bool				isSigned;
		int const			gradeRequiredToSign;
		int const			gradeRequiredToExecute;

	public:
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(cosnt Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string&	getName() const;
		bool 				isFormSigned() const;
		int 				getGradeRequiredToSign() const;
		int 				getGradeRequiredToExec() const;
		void 				beSigned(const Buraucrate& b);
		
		class GradeTooLowException: public std::exception
		{
			public:
				const char* 	what() const throw();
		};

		class GradeTooHighException: public std::exception
		{
			public:
				const char* 	what() const throw();
		};
};

std::ostream& operator<<(std::ostream& outputStream, const Form& form);

#endif
