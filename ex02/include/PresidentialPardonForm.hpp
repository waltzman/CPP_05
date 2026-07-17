/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:07:44 by mcombeau          #+#    #+#             */
/*   Updated: 2026/07/17 15:50:14 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_H
# define PRESIDENTIAL_PARDON_FORM_H

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const & other);
		PresidentialPardonForm(std::string const& target);
		~PresidentialPardonForm();

		PresidentialPardonForm &	operator=(PresidentialPardonForm const & other);

		std::string const &	getTarget() const;

		void	execute(Bureaucrat const& executor) const;

		static int const	gradeRequiredToSign = 25;
		static int const	gradeRequiredToExecute = 5;

	private:
		std::string	target;
};

#endif
