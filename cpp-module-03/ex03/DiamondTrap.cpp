/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:01:59 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/01 18:33:27 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() {
  std::cout << "DiamondTrap default constructor called" << std::endl;
  this->_name = "default";
  this->_hitPoints = FragTrap::_hitPoints;
  this->_energyPoints = ScavTrap::_energyPoints;
  this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
  std::cout << "DiamondTrap parameter constructor called" << std::endl;
  this->_name = name;
  this->_hitPoints = FragTrap::_hitPoints;
  this->_energyPoints = ScavTrap::_energyPoints;
  this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& source)
    : ClapTrap(source), FragTrap(source), ScavTrap(source) {
  std::cout << "DiamondTrap copy constructor called" << std::endl;
  *this = source;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& source) {
  std::cout << "DiamondTrap copy assignment operator called" << std::endl;
  if (this != &source) {
    this->_name = source._name;
    this->_hitPoints = source._hitPoints;
    this->_energyPoints = source._energyPoints;
    this->_attackDamage = source._attackDamage;
  }
  return *this;
}

void DiamondTrap::attack(std::string const& target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
  std::cout << "DiamondTrap " << this->_name << " says: \"My name is "
            << this->_name << " and my ClapTrap name is " << ClapTrap::_name
            << "\"." << std::endl;
}
