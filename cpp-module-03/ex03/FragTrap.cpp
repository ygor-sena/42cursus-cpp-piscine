/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:49:38 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/01 18:05:33 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default FragTrap") {
  this->_hitPoints = 100;
  this->_attackDamage = 30;
  std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  this->_hitPoints = 100;
  this->_attackDamage = 30;
  std::cout << "FragTrap parameter constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& source) : ClapTrap(source) {
  std::cout << "FragTrap copy constructor called" << std::endl;
  *this = source;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& source) {
  std::cout << "FragTrap copy assignment operator called" << std::endl;
  if (this != &source) {
    this->_name = source._name;
    this->_hitPoints = source._hitPoints;
    this->_energyPoints = source._energyPoints;
    this->_attackDamage = source._attackDamage;
  }
  return *this;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << this->_name << " says: 🙌 \"High five, guys!\" 🙌"
            << std::endl;
}

void FragTrap::attack(std::string const& target) {
  if (this->_hitPoints <= 0) {
    std::cout << "FragTrap " << this->_name << " is dead!" << std::endl;
    return;
  }
  if (this->_energyPoints <= 0) {
    std::cout << "FragTrap " << this->_name << " is without energy points!"
              << std::endl;
  } else {
    std::cout << "FragTrap " << this->_name << " attacks " << target
              << ", causing " << this->_attackDamage << " points of damage!"
              << std::endl;
  }
}
