/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:22:42 by rgohrig           #+#    #+#             */
/*   Updated: 2026/03/19 15:37:43 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "my_colors.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

static void put_debug(std::string const &info)
{
	std::cout << MAGENTA << info << ":" << RESET << std::endl;
}

int main(void)
{
	try
	{
		Bureaucrat mid("mid", 75);
		Bureaucrat cheater("cheater", 1);
		ShrubberyCreationForm home("home");
		AForm *home_pointer = &home;
		PresidentialPardonForm pardon("pardon");
		RobotomyRequestForm robo("robo");
		
		put_debug("test mid");
		mid.executeForm(*home_pointer); // Error: not signed
		mid.signAForm(home); 			// Ok: sign
		mid.executeForm(*home_pointer); // Ok: execute
		mid.executeForm(*home_pointer); // Ok: execute again
		mid.signAForm(home); 			// Error: already signed

		put_debug("test cheater");
		cheater.signAForm(pardon); 		// Ok: sign
		cheater.signAForm(robo); 		// Ok: sign
		cheater.executeForm(pardon); 	// Ok: execute
		cheater.executeForm(robo); 		// Ok: execute
		cheater.executeForm(robo); 		// Ok: execute
		cheater.executeForm(robo); 		// Ok: execute
		cheater.executeForm(robo);		// Ok: execute
		cheater.executeForm(robo);		// Ok: execute

		put_debug("print all");
		std::cout << mid << "\n"
			<< cheater << "\n"
			<< home << "\n"
			<< pardon << "\n"
			<< robo << "\n";
	
		Intern worker = {};

		worker.makeForm("shrubbery creation", "home");
	
	}
	catch(const std::exception& e)
	{
		std::cout << RED "!!!BIG ERROR THAT SHOULD NEVER HAPPEN: " << e.what() << RESET "\n";
	}
	return 0;
}
