/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:54:22 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 13:38:28 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
  std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(std::string const& type) : AMateria(type) {
  std::cout << "Ice " << this->_type << " constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
  *this = other;
  std::cout << "Ice " << this->_type << " copy constructor called" << std::endl;
}

Ice::~Ice() {
  std::cout << "Ice " << this->_type << " destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
  if (this != &other) {
    this->_type = other._type;
  }
  return *this;
}

AMateria* Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
