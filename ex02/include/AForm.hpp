/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:21:16 by rlobun            #+#    #+#             */
/*   Updated: 2026/07/17 11:27:39 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_H
#define AFORM_H

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		std::string const	name;
		std::string const	target;
		bool				isSigned;
		int const			gradeRequiredToSign;
		int const			gradeRequiredToExecute;

	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const std::string& name, int gradeToSign, int gradeToExecute, std::string target);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string&	getName() const;
		const std::string&	getTarget() const;
		bool 				isAFormSigned() const;
		int 				getGradeRequiredToSign() const;
		int 				getGradeRequiredToExecute() const;
		void 				beSigned(const Bureaucrat& b);
		virtual void		execute(const Bureaucrat& executor) const = 0;
		
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

		class FormNotSignedException: public std::exception
		{
			public:
				const char* 	what() const throw();
		};
};

std::ostream& operator<<(std::ostream& outputStream, const AForm& Aform);

#endif
