/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:31:18 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/04 16:09:48 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
  this->_brain = new Brain();
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : AAnimal(type) {
  this->_brain = new Brain();
  std::cout << "Dog type constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other) {
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
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
  }
  return (*this);
}

void Dog::makeSound() const {
  std::cout << "🐕🐶 Woof woof! 🐶🐕" << std::endl;
}
