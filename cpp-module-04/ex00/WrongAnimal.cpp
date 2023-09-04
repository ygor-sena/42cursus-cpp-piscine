/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:30:29 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/04 15:30:31 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
  std::cout << "WrongAnimal parameter constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
  *this = other;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  std::cout << "WrongAnimal copy assignment operator called" << std::endl;
  if (this != &other) {
    this->type = other.type;
  }
  return *this;
}

std::string WrongAnimal::getType() const { return this->type; }

void WrongAnimal::makeSound() const {
  std::cout << "🚫🚫 WrongAnimal sound 🚫🚫" << std::endl;
}
