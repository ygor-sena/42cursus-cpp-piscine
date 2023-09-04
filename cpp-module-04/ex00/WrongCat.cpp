/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:30:41 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/04 15:30:42 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
  std::cout << "WrongCat type constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  std::cout << "WrongCat copy constructor called" << std::endl;
  *this = other;
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

WrongCat &WrongCat::operator=(const WrongCat &other) {
  std::cout << "WrongCat assignation operator called" << std::endl;
  if (this != &other) this->type = other.type;
  return (*this);
}

void WrongCat::makeSound() const {
  std::cout << "мяу мяу!" << std::endl;
}
