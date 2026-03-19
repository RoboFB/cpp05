/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
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
#include "AForm.hpp"

// constructor
AForm::AForm(const std::string &name, const int gradeRequiredSign, const int gradeRequiredExecute) : 
	name_(name), 
	signed_(false), 
	gradeRequiredSign_(gradeRequiredSign), 
	gradeRequiredExecute_(gradeRequiredExecute)
{
	if (gradeRequiredSign_ < 1 || gradeRequiredExecute_ < 1)
		throw AForm::GradeTooHighException();
	if (gradeRequiredSign_ > 150 || gradeRequiredExecute_ > 150)
		throw AForm::GradeTooLowException();
}

// destructor
AForm::~AForm() {}

// copy constructor
AForm::AForm(const AForm &deepCopy) : 
	name_(deepCopy.name_),
	signed_(deepCopy.signed_),
	gradeRequiredSign_(deepCopy.gradeRequiredSign_),
	gradeRequiredExecute_(deepCopy.gradeRequiredExecute_) {};

// copy assignment operator
// no change of name_ because its const
AForm & AForm::operator=(const AForm &deepCopy)
{
	if (this != &deepCopy)
	{
		this->signed_ = deepCopy.signed_;
	}
	return *this;
}

// methods

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (!(bureaucrat.getGrade() <= gradeRequiredSign_))//better or equal
		throw AForm::GradeTooLowException();
	else if (signed_)
		throw AForm::AlreadySignedException();
	else
		signed_ = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!signed_)
		throw AForm::NotSignedException();
	else if (!(executor.getGrade() <= gradeRequiredExecute_))
		throw AForm::GradeTooLowException();
	else
		doExecuteUnchecked();
}

// getters/ setter
const std::string & AForm::getName() const
{
	return name_;
}

bool AForm::getSigned() const
{
	return signed_;
}

int AForm::getGradeRequiredSign() const
{
	return gradeRequiredSign_;
}

int AForm::getGradeRequiredExecute() const
{
	return gradeRequiredExecute_;
}

// exceptions
const char *AForm::GradeTooHighException::what() const noexcept
{
	return "grade too high";
}

const char *AForm::GradeTooLowException::what() const noexcept
{
	return "grade too low";
}

const char *AForm::AlreadySignedException::what() const noexcept
{
	return "AForm already signed";
}

const char *AForm::NotSignedException::what() const noexcept
{
	return "AForm not signed";
}

// prints: <name>, signed: <signed>, to sign: <gradeRequiredSign>, to execute: <gradeRequiredExecute>
std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << AForm.getName() 
		<< ", signed: " << AForm.getSigned()
		<< ", needs sign: " << AForm.getGradeRequiredSign()
		<< ", needs execute: " << AForm.getGradeRequiredExecute();
	return out;
}

