/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:07:34 by rgohrig           #+#    #+#             */
/*   Updated: 2026/03/23 11:33:24 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "my_colors.hpp"

// constructors / destructor
Intern::Intern() {}
Intern::~Intern() {}

Intern::Intern(const Intern &deepCopy)
{
	(void)deepCopy;
}

Intern & Intern::operator=(const Intern &deepCopy)
{
	(void)deepCopy;
	return *this;
}

AForm *Intern::createShrubbery(const std::string &target)
{
	std::cout << CYAN "Intern creates ShrubberyCreationForm" RESET "\n";
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target)
{
	std::cout << CYAN "Intern creates RobotomyRequestForm" RESET "\n";
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target)
{
	std::cout << CYAN "Intern creates PresidentialPardonForm" RESET "\n";
	return new PresidentialPardonForm(target);
}

// methods
AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	struct Match {
		AForm *(Intern::*functionPointer)(const std::string &);
        const char *nameNice;
        const char *nameFull;
	};
	
    static const Match table[3] = {
		{&Intern::createRobotomy,		"robotomy request",		"RobotomyRequestForm" },
		{&Intern::createPresidential,	"presidential pardon",	"PresidentialPardonForm"},
		{&Intern::createShrubbery,		"shrubbery creation",	"ShrubberyCreationForm"}
	};
	
	for (Match form : table) {
		if (formName == form.nameNice || formName == form.nameFull) {
			return (this->*form.functionPointer)(target);
		}
	}
	std::cout << CYAN "Intern creating failed because of invalid form name, please use: " 
		<< table[0].nameNice << ", " << table[1].nameNice << " or " << table[2].nameNice << "." RESET "\n";
	return nullptr;
}
