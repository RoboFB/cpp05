/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:05:55 by rgohrig           #+#    #+#             */
/*   Updated: 2026/03/19 13:08:16 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <ostream>
#include <iostream>

#include "my_colors.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

// constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	grade_ = grade;
};

// destructor
Bureaucrat::~Bureaucrat() {};

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &deepCopy) : name_(deepCopy.name_), grade_(deepCopy.grade_) {};

// copy assignment operator
// no change of name_ because its const
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &deepCopy)
{
	if (this != &deepCopy)
	{
		this->grade_ = deepCopy.grade_;
	}
	return *this;
};

// methods
void Bureaucrat::upgrade()
{
	if (grade_ <= 1)
		throw Bureaucrat::GradeTooHighException();
	grade_--;
};

void Bureaucrat::downgrade()
{
	if (grade_ >= 150)
		throw Bureaucrat::GradeTooLowException();
	grade_++;
};

// NEW: 
void Bureaucrat::signAForm(AForm &AForm)
{
	try {
		AForm.beSigned(*this);
		std::cout << BLUE
			<< name_
			<< " signed " << AForm.getName() << RESET << "\n";
	}
	catch(const std::exception& e) {
		std::cout << BLUE
			<< name_
			<< " couldn't sign " << AForm.getName() 
			<< " because " << e.what() << RESET << "\n";
	}
}

void Bureaucrat::executeForm(const AForm &AForm) const
{
	try {
		AForm.execute(*this);
		std::cout << YELLOW
			<< name_
			<< " executed " << AForm.getName() << RESET << "\n";
	}
	catch(const std::exception& e) {
		std::cout << YELLOW
			<< name_ 
			<< " couldn't execute " << AForm.getName() 
			<< " because " << e.what() << RESET << "\n";
	}
}

// getters/ setter
const std::string & Bureaucrat::getName() const
{
	return name_;
};

int Bureaucrat::getGrade() const
{
	return grade_;
};

// exceptions
const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "grade too high, max is 1";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "grade too low, min is 150";
}



// prints: <name>, bureaucrat grade <grade>
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}

