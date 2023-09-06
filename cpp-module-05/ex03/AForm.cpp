/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:20:45 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 15:30:51 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _gradeToSign(150), _gradeToExecute(150){
  std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string const& name, int const& gradeToSign,
           int const& gradeToExecute)
    : _name(name),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute),
      _isSigned(false) {
  std::cout << "AForm constructor called" << std::endl;
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw AForm::GradeTooHighException();
  } else if (gradeToSign > 150 || gradeToExecute > 150) {
    throw AForm::GradeTooLowException();
  }
}

AForm::AForm(AForm const& other)
    : _name(other._name),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute) {
  std::cout << "AForm copy constructor called" << std::endl;
  *this = other;
}

AForm::~AForm() { std::cout << "AForm destructor called" << std::endl; }

AForm& AForm::operator=(AForm const& other) {
  std::cout << "AForm assignation operator called" << std::endl;
  if (this != &other) {
    this->_isSigned = other._isSigned;
  }
  return *this;
}

std::string AForm::getName() const { return this->_name; }

int AForm::getGradeToSign() const { return this->_gradeToSign; }

int AForm::getGradeToExecute() const { return this->_gradeToExecute; }

bool AForm::getIsSigned() const { return this->_isSigned; }

void AForm::beSigned(Bureaucrat const& bureaucrat) {
  if (bureaucrat.getGrade() > this->_gradeToSign) {
    throw AForm::GradeTooLowException();
  } else {
    this->_isSigned = true;
  }
}

const char* AForm::GradeTooHighException::what() const throw() {
  return "Error: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Error: Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
  return "Error: Form not signed";
}

std::ostream& operator<<(std::ostream& os, AForm const& aform) {
  os << "AForm " << aform.getName() << " requires grade " << aform.getGradeToSign()
     << " to sign and grade " << aform.getGradeToExecute() << " to execute."
     << std::endl;
  if (aform.getIsSigned()) {
    os << "AForm is signed." << std::endl;
  } else {
    os << "AForm is not signed." << std::endl;
  }
  return os;
}
