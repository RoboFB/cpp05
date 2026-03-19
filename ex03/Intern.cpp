/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:07:34 by rgohrig           #+#    #+#             */
/*   Updated: 2026/03/19 15:40:36 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include "AForm.hpp"
// #include "Bureaucrat.hpp"
#include "Intern.hpp"


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
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target)
{
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
	return nullptr;
}



