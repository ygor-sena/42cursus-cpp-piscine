/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:40:01 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 13:38:56 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {
  std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type) {
  std::cout << "AMateria " << this->_type << " constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) {
  *this = other;
  std::cout << "AMateria " << this->_type << " copy constructor called"
            << std::endl;
}

AMateria::~AMateria() {
  std::cout << "AMateria " << this->_type << " destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
  if (this != &other) {
    this->_type = other._type;
  }
  return *this;
}

std::string const& AMateria::getType() const { return this->_type; }

void AMateria::use(ICharacter& target) {
  std::cout << "* " << this->_type << " uses its property at "
            << target.getName() << " *" << std::endl;
}
