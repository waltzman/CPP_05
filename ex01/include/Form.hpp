/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:21:16 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/28 10:46:50 by rlobun           ###   ########.fr       */
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
		const std::string 	name;
		bool				isSigned;
		const int 			gradeRequiredToSign;
		const int			gradeRequiredToExecute;

	public:
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string&	getName() const;
		bool				isFormSigned() const;
		int 				getGradeRequiredToSign() const;
		int 				getGradeRequiredToExecute() const;
		void 				beSigned(const Bureaucrat& b);
		
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
