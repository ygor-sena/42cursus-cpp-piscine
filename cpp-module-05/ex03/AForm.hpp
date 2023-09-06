/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:13:22 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 18:45:51 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
 private:
  std::string const _name;
  int const _gradeToSign;
  int const _gradeToExecute;
  bool _isSigned;

 public:
  AForm();  // Default constructor
  AForm(std::string const& name, int const& gradeToSign,
        int const& gradeToExecute);  // Parameter constructor
  AForm(AForm const& other);         // Copy constructor
  virtual ~AForm();                  // Destructor

  AForm& operator=(AForm const& other);  // Copy assignment operator

  // Getters
  std::string getName() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  bool getIsSigned() const;

  // Member functions
  void beSigned(Bureaucrat const& bureaucrat);
  virtual void execute(Bureaucrat const& executor) const = 0;

  // Exceptions
  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class FormNotSignedException : public std::exception {
   public:
	virtual const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, AForm const& aform);

#endif  // AFORM_HPP
