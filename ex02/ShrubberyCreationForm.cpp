/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:04:37 by mcombeau          #+#    #+#             */
/*   Updated: 2026/07/17 16:06:29 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(void)
		:	AForm("Shrubbery Creation Form",
					ShrubberyCreationForm::gradeRequiredToSign,
					ShrubberyCreationForm::gradeRequiredToExecute),
			target("Unknown")
{
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other)
		:	AForm(other),
			target(other.target)
{
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
		:	AForm("Shrubbery Creation Form",
					ShrubberyCreationForm::gradeRequiredToSign,
					ShrubberyCreationForm::gradeRequiredToExecute),
			target(target)
{
	std::cout << "ShrubberyCreationForm attribute constructor called." << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
	return ;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(
									ShrubberyCreationForm const & other)
{
	this->target = other.target;
	return (*this);
}

std::string const &	ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	std::ofstream	ofs;

	ofs.open((this->target + "_shrubbery").c_str(),
								std::ofstream::out );
	if (ofs.is_open())
	{
		ofs << "                            .         ;\n"
                 .              .              ;%     ;;\n" 
                   ,           ,                :;%  %;\n
                    :         ;                   :;%;'     .,\n
           ,.        %;     %;            ;        %;'    ,;\n
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n
              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n
               ;%;      %;        ;%;        % ;%;  ,%;'\n
                `%;.     ;%;     %;'         `;%%;.%;'\n
                 `:;%.    ;%%. %@;        %; ;@%;%'\n
                    `:%;.  :;bd%;          %;@%;'\n
                      `@%:.  :;%.         ;@@%;'\n
                        `@%.  `;@%.      ;@@%;\n     
                          `@%%. `@%%    ;@@%;\n     
                            ;@%. :@%%  %@@%;\n    
                              %@bd%%%bd%%:;\n  
                                #@%%%%%:;;\n
                                %@@%%%::;\n
                                %@@@%(o);  . '\n         
                                %@@@o%;:(.,'\n         
                            `.. %@@@o%::;\n    
                               `)@@@o%::;\n       
                                %@@(o)::;\n      
                               .%@@@@%::;\n
                               ;%@@@@%::;\n         
                              ;%@@@@%%:;;;.\n 
                          ...;%@@@@@%%:;;;;,..    Gilo97 "
		ofs.close();
	}
	return ;
}
