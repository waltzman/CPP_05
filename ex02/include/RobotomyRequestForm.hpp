/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:05:56 by mcombeau          #+#    #+#             */
/*   Updated: 2026/07/17 15:52:41 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_H
# define ROBOTOMY_REQUEST_FORM_H

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm const & other);
		RobotomyRequestForm(std::string const& target);
		~RobotomyRequestForm(void);

		RobotomyRequestForm &	operator=(RobotomyRequestForm const & other);

		std::string const &	getTarget() const;

		void	execute(Bureaucrat const& executor) const;

		static int const	gradeRequiredToSign = 72;
		static int const	gradeRequiredToExecute = 45;

	private:
		std::string	target;
};

#endif
