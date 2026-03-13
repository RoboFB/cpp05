/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:05:55 by rgohrig           #+#    #+#             */
/*   Updated: 2026/03/13 16:22:36 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <ostream>
#include <exception>


/* 
if out of range trows 	
Bureaucrat::GradeTooHighException / Bureaucrat::GradeTooLowException

*/


class Bureaucrat
{
	public:
		// constructors / destructor
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat();

		Bureaucrat(const Bureaucrat &deepCopy);
		Bureaucrat & operator=(const Bureaucrat &deepCopy);
	
		// methods
		void vitaminB();
		void selfSabotage();

		// getters/ setter
		const std::string & getName() const;
		int getGrade() const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	private:
		const std::string	name_;
		int 				grade_; // max: 1 min: 150

	
};

// prints: <name>, bureaucrat grade <grade>
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

