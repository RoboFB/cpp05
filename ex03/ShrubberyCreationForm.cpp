/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:01:55 by rgohrig           #+#    #+#             */
/*   Updated: 2026/03/18 16:18:29 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <ostream>
#include <exception>
#include <fstream>

#include "ShrubberyCreationForm.hpp"

// constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : 
	AForm("ShrubberyCreationForm", 145, 137),
	target_(target) {};
	
// destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {};
	
// copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &deepCopy) : 
	AForm(deepCopy),
	target_(deepCopy.target_) {};

// copy assignment operator
// no change of a lot becaus of const, but it copys the signed_ with the AForm overload
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &deepCopy)
{
	if (this != &deepCopy)
	{
		AForm::operator=(deepCopy);
	}
	return *this;
};

// methods
void ShrubberyCreationForm::doExecuteUnchecked() const
{
	std::ofstream outfile(target_ + "_shrubbery");
	outfile << "╔═══════════════════════════════════════╗\n"
			<< "║            🌲 SHRUBBERY 🌲            ║\n"
			<< "╠═══════════════════════════════════════╣\n"
			<< "║                                       ║\n"
			<< "║               \\/ |    |/              ║\n"
			<< "║            \\/ / \\||/  /_/___/_        ║\n"
			<< "║             \\/   |/ \\/                ║\n"
			<< "║        _\\__\\_\\   |  /_____/_          ║\n"
			<< "║               \\  | /          /       ║\n"
			<< "║      __ _-----`  |{,-----------~      ║\n"
			<< "║                \\ }{                   ║\n"
			<< "║                 }{{                   ║\n"
			<< "║                 }}{                   ║\n"
			<< "║                 {{}                   ║\n"
			<< "║            ,=-~{+->-._                ║\n"
			<< "╚═══════════════════════════════════════╝\n";
	return ;
}




// getters/ setter

const std::string & ShrubberyCreationForm::getTarget() const
{
	return target_;
}

// prints: <name>, signed: <signed>, to sign: <gradeRequiredSign>, to execute: <gradeRequiredExecute>
std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &ShrubberyCreationForm)
{
	out << static_cast<const AForm &>(ShrubberyCreationForm)
    	<< ", target: " << ShrubberyCreationForm.getTarget();
	return out;
}
