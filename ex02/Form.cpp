/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:05:55 by rgohrig           #+#    #+#             */
/*   Updated: 2026/03/17 15:00:25 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <ostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

// constructor
Form::Form(const std::string &name, const int gradeRequiredSign, const int gradeRequiredExecute) : 
	name_(name), 
	signed_(false), 
	gradeRequiredSign_(gradeRequiredSign), 
	gradeRequiredExecute_(gradeRequiredExecute)
{
	if (gradeRequiredSign_ < 1 || gradeRequiredExecute_ < 1)
		throw Form::GradeTooHighException();
	if (gradeRequiredSign_ > 150 || gradeRequiredExecute_ > 150)
		throw Form::GradeTooLowException();
};

// destructor
Form::~Form() {};

// copy constructor
Form::Form(const Form &deepCopy) : 
	name_(deepCopy.name_),
	signed_(deepCopy.signed_),
	gradeRequiredSign_(deepCopy.gradeRequiredSign_),
	gradeRequiredExecute_(deepCopy.gradeRequiredExecute_) {};

// copy assignment operator
// no change of name_ because its const
Form & Form::operator=(const Form &deepCopy)
{
	if (this != &deepCopy)
	{
		this->signed_ = deepCopy.signed_;
	}
	return *this;
};

// methods

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (!(bureaucrat.getGrade() <= gradeRequiredSign_))//better or equal
		throw Form::GradeTooLowException();
	else if (signed_)
		throw Form::AlreadySignedException();
	else
		signed_ = true;
}

// getters/ setter
const std::string & Form::getName() const
{
	return name_;
};

bool Form::getSigned() const
{
	return signed_;
};

int Form::getGradeRequiredSign() const
{
	return gradeRequiredSign_;
};

int Form::getGradeRequiredExecute() const
{
	return gradeRequiredExecute_;
};

// exceptions
const char *Form::GradeTooHighException::what() const noexcept
{
	return "grade too high";
}

const char *Form::GradeTooLowException::what() const noexcept
{
	return "grade too low";
}

const char *Form::AlreadySignedException::what() const noexcept
{
	return "form already signed";
}

// prints: <name>, signed: <signed>, to sign: <gradeRequiredSign>, to execute: <gradeRequiredExecute>
std::ostream &operator<<(std::ostream &out, const Form &Form)
{
	out << Form.getName() 
		<< ", signed: " << Form.getSigned()
		<< ", needs sign: " << Form.getGradeRequiredSign()
		<< ", needs execute: " << Form.getGradeRequiredExecute() << ".";
	return out;
}

