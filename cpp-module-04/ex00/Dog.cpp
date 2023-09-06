/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:30:12 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 22:08:54 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
  std::cout << "Dog type constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog copy constructor called" << std::endl;
  *this = other;
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog assignation operator called" << std::endl;
  if (this != &other) this->_type = other._type;
  return (*this);
}

void Dog::makeSound() const {
  std::cout << "🐕🐶 Woof woof! 🐶🐕" << std::endl;
}
