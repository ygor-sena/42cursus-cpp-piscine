/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:30:51 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/04 15:30:52 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
  std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
  std::cout << "Animal copy constructor called" << std::endl;
  *this = other;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal assignation operator called" << std::endl;
  if (this != &other) this->type = other.type;
  return (*this);
}

std::string Animal::getType() const { return (this->type); }

void Animal::makeSound() const {
  std::cout << "** generic animal sound **" << std::endl;
}
