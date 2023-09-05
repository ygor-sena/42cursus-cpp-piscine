/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:43:07 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 13:38:39 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
  std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(std::string const& type) : AMateria(type) {
  std::cout << "Cure " << this->_type << " constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
  *this = other;
  std::cout << "Cure " << this->_type << " copy constructor called"
            << std::endl;
}

Cure::~Cure() {
  std::cout << "Cure " << this->_type << " destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
  if (this != &other) {
    this->_type = other._type;
  }
  return *this;
}

AMateria* Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
