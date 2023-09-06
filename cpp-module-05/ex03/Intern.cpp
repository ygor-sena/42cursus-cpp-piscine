/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:51:33 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 20:35:09 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
  std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const& other) {
  std::cout << "Intern copy constructor called" << std::endl;
  *this = other;
}

Intern::~Intern() { std::cout << "Intern destructor called" << std::endl; }

Intern& Intern::operator=(Intern const& other) {
  std::cout << "Intern assignation operator called" << std::endl;
  if (this != &other) {
  }
  return *this;
}
AForm* Intern::makeForm(std::string const& formName,
                        std::string const& target) {
  AForm* (Intern::*formFunction[])(std::string const& target) = {
      &Intern::makeShrubberyCreationForm,
      &Intern::makeRobotomyRequestForm,
      &Intern::makePresidentialPardonForm,
  };
  std::string formTypes[] = {
      "shrubbery creation",
      "robotomy request",
      "presidential pardon",
  };

  for (int i = 0; i < 3; i++) {
    if (formName == formTypes[i]) {
	  std::cout << "Intern creates " << formName << " form" << std::endl;
	  return (this->*formFunction[i])(target);
	}
  }
  throw Intern::InvalidFormNameException();
}

AForm *Intern::makeShrubberyCreationForm(std::string const& target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(std::string const& target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(std::string const& target) {
  return new PresidentialPardonForm(target);
}

const char* Intern::InvalidFormNameException::what() const throw() {
  return "Error: Invalid form name";
}
