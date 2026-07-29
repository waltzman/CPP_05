/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:04:37 by mcombeau          #+#    #+#             */
/*   Updated: 2026/07/28 17:02:04 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(void)
		:	AForm("Shrubbery Creation Form", 145, 137, "Unknown")
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
		:	AForm("Shrubbery Creation Form", 145, 137),
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

void	ShrubberyCreationForm::executeFormAction () const
{
	std::ofstream	ofs;

	ofs.open((this->target + "_shrubbery").c_str(),
								std::ofstream::out );
	if (ofs.is_open())
	{
		ofs <<  "                              .         ;\n";
		ofs <<  "       .              .              ;%     ;;\n"; 
		ofs <<  "         ,           ,                :;%  %;\n";
		ofs <<  "          :         ;                   :;%;'     .,\n";
		ofs <<  " ,.        %;     %;            ;        %;'    ,;\n";
		ofs <<  "   ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
		ofs <<  "    %;       %;%;      ,  ;       %;  ;%;   ,%;'\n";
		ofs <<  "     ;%;      %;        ;%;        % ;%;  ,%;'\n";
		ofs <<  "      `%;.     ;%;     %;'         `;%%;.%;'\n";
		ofs <<  "       `:;%.    ;%%. %@;        %; ;@%;%'\n";
		ofs <<  "          `:%;.  :;bd%;          %;@%;'\n";
		ofs <<  "            `@%:.  :;%.         ;@@%;'\n";
		ofs <<  "              `@%.  `;@%.      ;@@%;\n";     
		ofs <<  "                `@%%. `@%%    ;@@%;\n";     
		ofs <<  "                  ;@%. :@%%  %@@%;\n";    
		ofs <<  "                    %@bd%%%bd%%:;\n";  
		ofs <<  "                      #@%%%%%:;;\n";
		ofs <<  "                      %@@%%%::;\n";
		ofs <<  "                      %@@@%(o);  . '\n";         
		ofs <<  "                      %@@@o%;:(.,'\n";         
		ofs <<  "                  `.. %@@@o%::;\n";    
		ofs <<  "                     `)@@@o%::;\n";       
		ofs <<  "                      %@@(o)::;\n";      
		ofs <<  "                     .%@@@@%::;\n";
		ofs <<  "                     ;%@@@@%::;\n";         
		ofs <<  "                    ;%@@@@%%:;;;.\n"; 
		ofs <<  "                ...;%@@@@@%%:;;;;,..    Gilo97 ";
		ofs.close();
	}
	return ;
}
