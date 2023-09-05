/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:01:14 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 13:38:47 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default") {
  std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const& name) : _name(name) {
  std::cout << "Character " << this->_name << " constructor called"
            << std::endl;
}

Character::Character(const Character& other) {
  *this = other;
  std::cout << "Character " << this->_name << " copy constructor called"
            << std::endl;
}

Character::~Character() {
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] != NULL) {
      delete this->_inventory[i];
    }
  }
  std::cout << "Character " << this->_name << " destructor called" << std::endl;
}

Character& Character::operator=(const Character& other) {
  if (this != &other) {
    this->_name = other._name;
    for (int i = 0; i < 4; i++) {
      if (this->_inventory[i] != NULL) {
        delete this->_inventory[i];
      }
      this->_inventory[i] = other._inventory[i]->clone();
    }
  }
  return *this;
}

std::string const& Character::getName() const { return this->_name; }

void Character::equip(AMateria* m) {
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] == NULL) {
      this->_inventory[i] = m;
      break;
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx < 4) {
    this->_inventory[idx] = NULL;
  }
}

void Character::use(int idx, ICharacter& target) {
  if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL) {
    this->_inventory[idx]->use(target);
  }
}
