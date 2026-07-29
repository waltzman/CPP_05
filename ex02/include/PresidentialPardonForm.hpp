/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:07:44 by mcombeau          #+#    #+#             */
/*   Updated: 2026/07/28 15:44:23 by rlobun           ###   ########.fr       */
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

	private:
		std::string	target;
		virtual void	executeFormAction() const;
};

#endif
