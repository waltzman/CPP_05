/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:02:43 by mcombeau          #+#    #+#             */
/*   Updated: 2026/07/17 15:52:51 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_H
# define SHRUBBERY_CREATION_FORM_H

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const & other);
		ShrubberyCreationForm(std::string const & target);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & other);

		std::string const &	getTarget() const;

		void	execute(Bureaucrat const& executor) const;

		static int const	gradeRequiredToSign = 145;
		static int const	gradeRequiredToExecute = 137;

	private:
		std::string					target;
		static std::string const	shrubbery;
		static std::string const	shrubberyAlt;
};

#endif
