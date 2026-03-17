/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:22:42 by rgohrig           #+#    #+#             */
/*   Updated: 2026/03/17 15:05:00 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "my_colors.hpp"

static void put_debug(std::string const &info)
{
	std::cout << MAGENTA << info << ":" << RESET << std::endl;
}

int main(void)
{
	put_debug("invalid inits of forms");
	try {
		Form invalid("invalid", 151, 151);
	}
	catch(const std::exception& e) {
		std::cout << "to low: " << e.what() << '\n';
	}
	
	try {
		Form invalid("invalid", 150, -10);
	}
	catch(const std::exception& e) {
		std::cout << "to high: " << e.what() << '\n';
	}
	

	Bureaucrat mid("mid", 75);
	Form easy("easy", 150, 150);
	Form exact("exact", 75, 1);
	Form hard("hard", 1, 1);
	
	put_debug("test mid ok");
	mid.signForm(easy);
	mid.signForm(exact);
	
	put_debug("test mid fail");
	mid.signForm(easy);
	mid.signForm(exact);
	mid.signForm(hard);
	
	put_debug("print mid and exact");
	std::cout << mid << "\n" << exact << "\n";

	return 0;
}