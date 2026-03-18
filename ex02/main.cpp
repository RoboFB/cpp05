/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:22:42 by rgohrig           #+#    #+#             */
/*   Updated: 2026/03/18 17:14:22 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "my_colors.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

static void put_debug(std::string const &info)
{
	std::cout << MAGENTA << info << ":" << RESET << std::endl;
}

int main(void)
{
	
	
	
	
	put_debug("small test");
	Bureaucrat mid("mid", 75);
	ShrubberyCreationForm home("home");
	

	// put_debug("test mid ok");
	// mid.signAForm(easy);
	// mid.signAForm(exact);
	
	// put_debug("test mid fail");
	// mid.signAForm(easy);
	// mid.signAForm(exact);
	// mid.signAForm(hard);

	AForm *pointer = &home;

	try
	{
		/* code */
		// pointer->execute(mid);
		mid.executeForm(*pointer);
		mid.signAForm(home);
		mid.executeForm(*pointer);
		mid.executeForm(*pointer);
		mid.signAForm(home);
	}
	catch(const std::exception& e)
	{
		std::cout << "BIG ERROR" << e.what() << '\n';
	}
	
	
	put_debug("print mid and home");
	std::cout << mid << "\n" << home << "\n";

	return 0;
}