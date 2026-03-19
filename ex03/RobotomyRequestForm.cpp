/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
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
#include <ctime>

#include "my_colors.hpp"
#include "RobotomyRequestForm.hpp"

// constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : 
	AForm("RobotomyRequestForm", 72, 45),
	target_(target) {}
	
// destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &deepCopy) : 
	AForm(deepCopy),
	target_(deepCopy.target_) {}

// copy assignment operator
// no change of a lot becaus of const, but it copys the signed_ with the AForm overload
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &deepCopy)
{
	if (this != &deepCopy)
	{
		AForm::operator=(deepCopy);
	}
	return *this;
}

// methods
void RobotomyRequestForm::doExecuteUnchecked() const
{
	static unsigned int seed;

	if (seed == 0)
	{
		seed = std::time(NULL);
		std::srand(seed);
	}
    std::cout << "DDRRRIIILLLLLLLLLLLL TRRRRR TRR\n";
    if (std::rand() % 2 == 0)
        std::cout << "Robotomized " << target_ << GREEN << " successfully" << RESET << ".\n";
    else
        std::cout << "Robotomy " << target_ << RED << " failed" << RESET << ".\n";
}




// getters/ setter

const std::string & RobotomyRequestForm::getTarget() const
{
	return target_;
}

// prints: <name>, signed: <signed>, to sign: <gradeRequiredSign>, to execute: <gradeRequiredExecute>
std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &RobotomyRequestForm)
{
	out << static_cast<const AForm &>(RobotomyRequestForm)
    	<< ", target: " << RobotomyRequestForm.getTarget();
	return out;
}
