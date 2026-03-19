/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:05:55 by rgohrig           #+#    #+#             */
/*   Updated: 2026/03/16 16:05:14 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <ostream>
#include <exception>

class Bureaucrat; // forward declaration

/*
AForm trows if out of range (1-150):
- AForm::GradeTooHighException
- AForm::GradeTooLowException
*/
class AForm
{
	public:
		// constructors / destructor
		AForm() = delete; // delete because of the const name_
		AForm(const std::string &name, const int gradeRequiredSign = 150, const int gradeRequiredExecute = 150);
		virtual ~AForm();

		AForm(const AForm &deepCopy);
		AForm & operator=(const AForm &deepCopy);
	
		// methods
		void beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const & executor) const;
		
		// getters/ setter
		const std::string & getName() const;
		bool getSigned() const;
		int getGradeRequiredSign() const;
		int getGradeRequiredExecute() const;
		
		// exceptions forward-declared
		class GradeTooHighException;
        class GradeTooLowException;
		class AlreadySignedException;
		class NotSignedException;
		
	protected:
		// only in derived classes
		virtual void doExecuteUnchecked() const = 0;
		
	private:
		const std::string	name_;
		bool				signed_;
		const int			gradeRequiredSign_; // (1-150)
		const int			gradeRequiredExecute_; // (1-150)

};

class AForm::GradeTooHighException : public std::exception {
	public:	const char *what() const noexcept;
};

class AForm::GradeTooLowException : public std::exception {
	public:	const char *what() const noexcept;
};

class AForm::AlreadySignedException : public std::exception {
	public: const char *what() const noexcept;
};

class AForm::NotSignedException : public std::exception {
	public:	const char *what() const noexcept;
};

// prints: <name>, signed: <signed>, to sign: <gradeRequiredSign>, to execute: <gradeRequiredExecute>
std::ostream &operator<<(std::ostream &out, const AForm &AForm);

