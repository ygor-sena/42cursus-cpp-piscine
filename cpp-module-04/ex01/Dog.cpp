/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:31:18 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/04 15:31:19 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
  this->_brain = new Brain();
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
  this->_brain = new Brain();
  std::cout << "Dog type constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog copy constructor called" << std::endl;
  *this = other;
}

Dog::~Dog() {
  delete this->_brain;
  std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog assignation operator called" << std::endl;
  if (this != &other) {
	this->type = other.type;
	this->_brain = new Brain(*other._brain);
  }
  return (*this);
}

void Dog::makeSound() const {
  std::cout << "🐕🐶 Woof woof! 🐶🐕" << std::endl;
}
