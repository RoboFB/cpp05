/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:07:34 by rgohrig           #+#    #+#             */
/*   Updated: 2026/03/19 15:12:03 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		// constructors / destructor
		Intern();
		~Intern();

		Intern(const Intern &deepCopy);
		Intern & operator=(const Intern &deepCopy);

		// methods
		AForm *makeForm(const std::string &formName, const std::string &target);

		// getters/ setters

	private:
		AForm *createShrubbery(const std::string &target);
		AForm *createRobotomy(const std::string &target);
		AForm *createPresidential(const std::string &target);
};
