/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:01:55 by rgohrig           #+#    #+#             */
/*   Updated: 2026/03/18 16:18:29 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>
#include <fstream>

#include "PresidentialPardonForm.hpp"

// constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : 
	AForm("PresidentialPardonForm", 25, 5),
	target_(target) {}
	
// destructor
PresidentialPardonForm::~PresidentialPardonForm() {}
	
// copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &deepCopy) : 
	AForm(deepCopy),
	target_(deepCopy.target_) {}

// copy assignment operator
// no change of a lot becaus of const, but it copys the signed_ with the AForm overload
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &deepCopy)
{
	if (this != &deepCopy)
	{
		AForm::operator=(deepCopy);
	}
	return *this;
}

// methods
void PresidentialPardonForm::doExecuteUnchecked() const
{
	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return ;
}




// getters/ setter

const std::string & PresidentialPardonForm::getTarget() const
{
	return target_;
}

// prints: <name>, signed: <signed>, to sign: <gradeRequiredSign>, to execute: <gradeRequiredExecute>
std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &PresidentialPardonForm)
{
	out << static_cast<const AForm &>(PresidentialPardonForm)
    	<< ", target: " << PresidentialPardonForm.getTarget();
	return out;
}
