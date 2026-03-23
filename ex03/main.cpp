/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:22:42 by rgohrig           #+#    #+#             */
/*   Updated: 2026/03/23 12:08:24 by rgohrig          ###   ########.fr       */
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
	AForm *home = nullptr;
	AForm *pardon = nullptr;
	AForm *robo = nullptr;
	
	try
	{
		Bureaucrat mid("mid", 75);
		Bureaucrat cheater("cheater", 1);
		
		Intern worker = {};
		
		put_debug("test Intern");
		AForm *invalid_nullptr = worker.makeForm("invalid name not a form", "target doesn't matter");
		if (invalid_nullptr != nullptr)
		{
			delete invalid_nullptr;
			throw std::logic_error("Broke somehow makeForm because it shouldn't work with invalid form name");
		}
		
		home = worker.makeForm("shrubbery creation", "home");
		pardon = worker.makeForm("presidential pardon", "pardon");
		robo = worker.makeForm("robotomy request", "robo");
		if (home == nullptr || pardon == nullptr || robo == nullptr)
		{
			throw std::logic_error("Broke somehow makeForm because it should generate valid forms");
		}
		
		put_debug("test mid");
		mid.executeForm(*home);			// Error: not signed
		mid.signAForm(*home); 			// Ok: sign
		mid.executeForm(*home); 		// Ok: execute
		mid.executeForm(*home); 		// Ok: execute again
		mid.signAForm(*home); 			// Error: already signed

		put_debug("test cheater");
		cheater.signAForm(*pardon); 	// Ok: sign
		cheater.signAForm(*robo); 		// Ok: sign
		cheater.executeForm(*pardon); 	// Ok: execute
		cheater.executeForm(*robo); 	// Ok: execute
		cheater.executeForm(*robo); 	// Ok: execute
		cheater.executeForm(*robo); 	// Ok: execute
		cheater.executeForm(*robo);		// Ok: execute
		cheater.executeForm(*robo);		// Ok: execute

		put_debug("print all");
		std::cout << mid << "\n"
			<< cheater << "\n"
			<< *home << "\n"
			<< *pardon << "\n"
			<< *robo << "\n";
	}
	catch(const std::exception& e)
	{
		std::cout << RED "!!!BIG ERROR THAT SHOULD NEVER HAPPEN: " << e.what() << RESET "\n";
	}
	delete home;
	delete pardon;
	delete robo;
	return 0;
}
