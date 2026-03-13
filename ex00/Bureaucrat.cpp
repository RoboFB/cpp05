/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:05:55 by rgohrig           #+#    #+#             */
/*   Updated: 2026/03/13 16:22:30 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <ostream>

#include "Bureaucrat.hpp"

/* 
if out of range trows 	
Bureaucrat::GradeTooHighException / Bureaucrat::GradeTooLowException

*/

// constructors / destructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name), grade_(grade)
{
	if (grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
};

Bureaucrat::~Bureaucrat() {};

Bureaucrat::Bureaucrat(const Bureaucrat &deepCopy) : name_(deepCopy.name_), grade_(deepCopy.grade_) {};

// no change of name- because its const
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &deepCopy)
{
	if (this != &deepCopy)
	{
		// this->name_ = deepCopy.name_;
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

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade too low";
}


	

// prints: <name>, bureaucrat grade <grade>
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}

