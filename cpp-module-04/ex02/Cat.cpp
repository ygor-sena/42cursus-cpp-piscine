/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:31:07 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/04 16:10:25 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
  _brain = new Brain();
  std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type) : AAnimal(type) {
  this->_brain = new Brain();
  std::cout << "Cat type constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other) {
  std::cout << "Cat copy constructor called" << std::endl;
  *this = other;
}

Cat::~Cat() {
  delete this->_brain;
  std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat assignation operator called" << std::endl;
  if (this != &other) {
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
  }
  return (*this);
}

void Cat::makeSound() const {
  std::cout << "🐈🐱 Meow meow! 🐱🐈" << std::endl;
}
