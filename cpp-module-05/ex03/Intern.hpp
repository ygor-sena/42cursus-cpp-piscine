/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:47:22 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 20:36:12 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 private:
  AForm* makeShrubberyCreationForm(std::string const& target);
  AForm* makeRobotomyRequestForm(std::string const& target);
  AForm* makePresidentialPardonForm(std::string const& target);
 public:
  Intern();                                // Default constructor
  Intern(Intern const& other);             // Copy constructor
  ~Intern();                               // Destructor
  Intern& operator=(Intern const& other);  // Copy assignment operator

  // Member functions
  AForm* makeForm(std::string const& formName, std::string const& target);

  // Exceptions
  class InvalidFormNameException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

#endif  // INTERN_HPP
