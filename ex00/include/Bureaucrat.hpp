/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:05:55 by rgohrig           #+#    #+#             */
/*   Updated: 2026/03/16 16:05:14 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <ostream>
#include <exception>

/* 
Bureaucrat trows if out of range (1-150):
- Bureaucrat::GradeTooHighException
- Bureaucrat::GradeTooLowException
*/
class Bureaucrat
{
	public:
		// constructors / destructor
		Bureaucrat() = delete; // delete because of the const name_
		Bureaucrat(const std::string &name, int grade = 150);
		~Bureaucrat();

		Bureaucrat(const Bureaucrat &deepCopy);
		Bureaucrat & operator=(const Bureaucrat &deepCopy);
	
		// methods
		void vitaminB();
		void selfSabotage();

		// getters/ setter
		const std::string & getName() const;
		int getGrade() const;

		// exceptions forward-declared
		class GradeTooHighException;
        class GradeTooLowException;

	private:
		const std::string	name_;
		int 				grade_; // max: 1 min: 150	
};

class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		const char *what() const noexcept;
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		const char *what() const noexcept;
};

// prints: <name>, bureaucrat grade <grade>
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
