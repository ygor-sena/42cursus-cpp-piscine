/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:30:51 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/04 16:10:47 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
  std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
  std::cout << "AAnimal type constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) {
  std::cout << "AAnimal copy constructor called" << std::endl;
  *this = other;
}

AAnimal::~AAnimal() { std::cout << "AAnimal destructor called" << std::endl; }

AAnimal &AAnimal::operator=(const AAnimal &other) {
  std::cout << "AAnimal assignation operator called" << std::endl;
  if (this != &other) this->_type = other._type;
  return (*this);
}

std::string AAnimal::getType() const { return (this->_type); }
