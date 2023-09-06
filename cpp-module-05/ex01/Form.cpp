/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:20:45 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 15:30:51 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _gradeToSign(150), _gradeToExecute(150){
  std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string const& name, int const& gradeToSign,
           int const& gradeToExecute)
    : _name(name),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute),
      _isSigned(false) {
  std::cout << "Form constructor called" << std::endl;
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw Form::GradeTooHighException();
  } else if (gradeToSign > 150 || gradeToExecute > 150) {
    throw Form::GradeTooLowException();
  }
}

Form::Form(Form const& other)
    : _name(other._name),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute) {
  std::cout << "Form copy constructor called" << std::endl;
  *this = other;
}

Form::~Form() { std::cout << "Form destructor called" << std::endl; }

Form& Form::operator=(Form const& other) {
  std::cout << "Form assignation operator called" << std::endl;
  if (this != &other) {
    this->_isSigned = other._isSigned;
  }
  return *this;
}

std::string Form::getName() const { return this->_name; }

int Form::getGradeToSign() const { return this->_gradeToSign; }

int Form::getGradeToExecute() const { return this->_gradeToExecute; }

bool Form::getIsSigned() const { return this->_isSigned; }

void Form::beSigned(Bureaucrat const& bureaucrat) {
  if (bureaucrat.getGrade() > this->_gradeToSign) {
    throw Form::GradeTooLowException();
  } else {
    this->_isSigned = true;
  }
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, Form const& form) {
  os << "Form " << form.getName() << " requires grade " << form.getGradeToSign()
     << " to sign and grade " << form.getGradeToExecute() << " to execute."
     << std::endl;
  if (form.getIsSigned()) {
    os << "Form is signed." << std::endl;
  } else {
    os << "Form is not signed." << std::endl;
  }
  return os;
}
