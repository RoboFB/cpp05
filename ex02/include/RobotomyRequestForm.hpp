/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
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

class RobotomyRequestForm : public AForm
{
	public:
		// constructors / destructor
		RobotomyRequestForm() = delete; // delete because of the const name_
		RobotomyRequestForm(const std::string &target);
		
		~RobotomyRequestForm() override;

		RobotomyRequestForm(const RobotomyRequestForm &deepCopy);
		RobotomyRequestForm & operator=(const RobotomyRequestForm &deepCopy);
	
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
std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &RobotomyRequestForm);
