/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:22:42 by rgohrig           #+#    #+#             */
/*   Updated: 2026/03/16 16:04:16 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "my_colors.hpp"

static void put_debug(std::string const &info)
{
	std::cout << MAGENTA << info << RESET << std::endl;
}

int main(void)
{
	Bureaucrat first = {"first", 2};
	Bureaucrat last = {"last", 149};
	
	put_debug("init values:");
	std::cout << first << "\n" << last << "\n\n";
	
	put_debug("first 2x up/vitaminB:");
	try {
		first.vitaminB();
		std::cout << first << "\n";
		first.vitaminB();
	}
	catch(const std::exception& e) {
		std::cerr << "ERROR caught: " << e.what() << "\n";
	}
	std::cout << first << "\n\n";
	
	put_debug("last 2x down/selfSabotage:");
	try {
		last.selfSabotage();
		std::cout << last << "\n";
		last.selfSabotage();
	}
	catch(const std::exception& e) {
		std::cerr << "ERROR caught: " << e.what() << "\n";
	}
	std::cout << last << "\n\n";
	
	put_debug("crazy default grade:");
	Bureaucrat crazy = {"crazy"};
	std::cout << crazy << "\n\n";
	
	put_debug("copy first:");
	Bureaucrat copy = first;
	std::cout << copy << "\n";
	
	put_debug("assign first:");
	Bureaucrat assign("assign");
	assign = first;
	std::cout << assign << "\n";
	
	put_debug("getters first:");
	std::cout << "Name: " << first.getName() << ", Grade: " << first.getGrade() << "\n";
	return 0;
}
