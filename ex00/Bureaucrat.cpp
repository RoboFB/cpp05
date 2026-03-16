/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:05:55 by rgohrig           #+#    #+#             */
/*   Updated: 2026/03/16 16:16:50 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <string>
#include <ostream>

// constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name), grade_(grade)
{
	if (grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
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
void Bureaucrat::vitaminB()
{
	if (grade_ <= 1)
		throw Bureaucrat::GradeTooHighException();
	grade_--;
};

void Bureaucrat::selfSabotage()
{
	if (grade_ >= 150)
		throw Bureaucrat::GradeTooLowException();
	grade_++;
};

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
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade too high, max is 1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade too low, min is 150";
}


	

// prints: <name>, bureaucrat grade <grade>
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}

