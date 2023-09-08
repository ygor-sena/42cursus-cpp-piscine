/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:09:20 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/07 21:42:16 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("default") {
  std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
  std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other)
    : AForm(other), _target(other._target) {
  std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
  *this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    RobotomyRequestForm const& other) {
  std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
  if (this != &other) {
    this->_target = other._target;
  }
  return *this;
}

std::string RobotomyRequestForm::getTarget() const { return this->_target; }

void RobotomyRequestForm::_execute(void) const {
    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() % 2 == 0) {
      std::cout << this->_target << " has been robotomized successfully."
                << std::endl;
    } else {
      std::cout << this->_target << " robotomization failed." << std::endl;
    }
}
