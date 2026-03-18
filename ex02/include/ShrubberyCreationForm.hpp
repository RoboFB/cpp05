/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:01:55 by rgohrig           #+#    #+#             */
/*   Updated: 2026/03/18 16:57:13 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <ostream>
#include <exception>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		// constructors / destructor
		ShrubberyCreationForm() = delete; // delete because of the const name_
		ShrubberyCreationForm(const std::string &target);
		
		~ShrubberyCreationForm() override;

		ShrubberyCreationForm(const ShrubberyCreationForm &deepCopy);
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &deepCopy);
	
		// methods
		
		
		// getters/ setter
		const std::string & getTarget() const;

	protected:
		// protected so that the unchecked can not be called form outside the class.
		// It should be only used in execute of the base class
		void doExecuteUnchecked() const override;
	
	private:
		const std::string target_;
};

// prints: <name>, signed: <signed>, to sign: <gradeRequiredSign>, to execute: <gradeRequiredExecute>
std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &ShrubberyCreationForm);
