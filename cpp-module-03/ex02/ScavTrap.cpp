/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:01:47 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/01 18:05:08 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default ScavTrap") {
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
  std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
  std::cout << "ScavTrap parameter constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& source) : ClapTrap(source) {
  std::cout << "ScavTrap copy constructor called" << std::endl;
  *this = source;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& source) {
  std::cout << "ScavTrap copy assignment operator called" << std::endl;
  if (this != &source) {
    this->_name = source._name;
    this->_hitPoints = source._hitPoints;
    this->_energyPoints = source._energyPoints;
    this->_attackDamage = source._attackDamage;
  }
  return *this;
}

void ScavTrap::attack(std::string const& target) {
  if (this->_hitPoints <= 0) {
    std::cout << "ScavTrap " << this->_name << " is dead!" << std::endl;
    return;
  }
  if (this->_energyPoints <= 0) {
    std::cout << "ScavTrap " << this->_name << " is without energy points!"
              << std::endl;
  } else {
    std::cout << "ScavTrap " << this->_name << " attacks " << target
              << ", causing " << this->_attackDamage << " points of damage!"
              << std::endl;
    this->_energyPoints--;
  }
}

void ScavTrap::guardGate(void) {
  std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode."
            << std::endl;
}
