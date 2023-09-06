/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:13:22 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 16:50:48 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 private:
  std::string const _name;
  int const _gradeToSign;
  int const _gradeToExecute;
  bool _isSigned;

 public:
  Form();                           // Default constructor
  Form(std::string const& name, int const& gradeToSign,
       int const& gradeToExecute);  // Parameter constructor
  Form(Form const& other);          // Copy constructor
  ~Form();                          // Destructor

  Form& operator=(Form const& other);  // Copy assignment operator

  // Getters
  std::string getName() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  bool getIsSigned() const;

  // Member functions
  void beSigned(Bureaucrat const& bureaucrat);

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

std::ostream& operator<<(std::ostream& os, Form const& form);

#endif  // FORM_HPP
