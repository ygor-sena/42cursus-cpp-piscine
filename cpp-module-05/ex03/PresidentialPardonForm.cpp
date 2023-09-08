/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:01:55 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/07 21:42:27 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("default") {
  std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
  std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const& other)
    : AForm(other), _target(other._target) {
  std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
  *this = other;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    PresidentialPardonForm const& other) {
  std::cout << "PresidentialPardonForm assignation operator called"
            << std::endl;
  if (this != &other) {
    this->_target = other._target;
  }
  return *this;
}

std::string PresidentialPardonForm::getTarget() const { return this->_target; }

void PresidentialPardonForm::_execute(void) const {
  std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
