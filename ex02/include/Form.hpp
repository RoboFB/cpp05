/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
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
Form trows if out of range (1-150):
- Form::GradeTooHighException
- Form::GradeTooLowException
*/
class Form
{
	public:
		// constructors / destructor
		Form() = delete; // delete because of the const name_
		Form(const std::string &name, const int gradeRequiredSign = 150, const int gradeRequiredExecute = 150);
		~Form();

		Form(const Form &deepCopy);
		Form & operator=(const Form &deepCopy);
	
		// methods
		void beSigned(const Bureaucrat &bureaucrat);
		

		// getters/ setter
		const std::string & getName() const;
		bool getSigned() const;
		int getGradeRequiredSign() const;
		int getGradeRequiredExecute() const;

		// exceptions forward-declared
		class GradeTooHighException;
        class GradeTooLowException;
		class AlreadySignedException;

	private:
		const std::string	name_;
		bool				signed_;
		const int			gradeRequiredSign_; // (1-150)
		const int			gradeRequiredExecute_; // (1-150)
};

class Form::GradeTooHighException : public std::exception
{
	public:
		const char *what() const noexcept;
};

class Form::GradeTooLowException : public std::exception
{
	public:
		const char *what() const noexcept;
};

class Form::AlreadySignedException : public std::exception
{
	public:
		const char *what() const noexcept;
};

// prints: <name>, signed: <signed>, to sign: <gradeRequiredSign>, to execute: <gradeRequiredExecute>
std::ostream &operator<<(std::ostream &out, const Form &Form);

