/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:43:09 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/07 21:52:33 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
  std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : _name(name) {
  std::cout << "Bureaucrat constructor called" << std::endl;
  if (grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else if (grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  } else {
    this->_grade = grade;
  }
}

Bureaucrat::Bureaucrat(Bureaucrat const& other) : _name(other._name) {
  std::cout << "Bureaucrat copy constructor called" << std::endl;
  *this = other;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other) {
  std::cout << "Bureaucrat assignation operator called" << std::endl;
  if (this != &other) {
    this->_grade = other._grade;
  }
  return *this;
}

std::string const Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::incrementGrade() {
  if (this->_grade - 1 < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else {
    this->_grade--;
  }
}

void Bureaucrat::decrementGrade() {
  if (this->_grade + 1 > 150) {
    throw Bureaucrat::GradeTooLowException();
  } else {
    this->_grade++;
  }
}

void Bureaucrat::signForm(Form& form) {
  try {
	form.beSigned(*this);
	std::cout << this->_name << " signs " << form.getName() << std::endl;
  } catch (std::exception& e) {
	std::cerr << this->_name << " cannot sign " << form.getName() << " because "
			  << e.what() << std::endl;
  }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return os;
}
