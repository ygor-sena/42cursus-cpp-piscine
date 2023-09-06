/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:40:22 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 18:40:36 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
 private:
  std::string const _name;
  int _grade;

 public:
  Bureaucrat();                                    // Default constructor
  Bureaucrat(std::string const& name, int grade);  // Parameter constructor
  Bureaucrat(Bureaucrat const& other);             // Copy constructor
  ~Bureaucrat();                                   // Destructor

  Bureaucrat& operator=(Bureaucrat const& other);  // Copy assignment operator

  // Getters
  std::string const getName() const;
  int getGrade() const;

  // Member functions
  void incrementGrade();
  void decrementGrade();
  void signForm(AForm& form);
  void executeForm(AForm const& form);

  // Exceptions
  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

// Insertion operator overload
std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat);

#endif  // BUREAUCRAT_HPP
