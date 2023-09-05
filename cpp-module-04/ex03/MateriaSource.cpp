/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:14:55 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 13:38:07 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  std::cout << "MateriaSource default constructor called" << std::endl;
  for (int i = 0; i < 4; i++) {
    this->_inventory[i] = NULL;
  }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
  *this = other;
  std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] != NULL) {
      delete this->_inventory[i];
    }
  }
  std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
  if (this != &other) {
    for (int i = 0; i < 4; i++) {
      if (this->_inventory[i] != NULL) {
        delete this->_inventory[i];
      }
      this->_inventory[i] = other._inventory[i]->clone();
    }
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] == NULL) {
      this->_inventory[i] = m;
      break;
    }
  }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] != NULL && this->_inventory[i]->getType() == type) {
      return this->_inventory[i]->clone();
    }
  }
  return NULL;
}
