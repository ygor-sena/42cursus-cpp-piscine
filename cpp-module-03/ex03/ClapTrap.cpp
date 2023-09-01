/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:17:57 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/31 17:04:56 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("Default ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& source) {
  std::cout << "ClapTrap copy constructor called" << std::endl;
  *this = source;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& source) {
  std::cout << "ClapTrap copy assignment operator called" << std::endl;
  if (this != &source) {
    this->_name = source._name;
    this->_hitPoints = source._hitPoints;
    this->_energyPoints = source._energyPoints;
    this->_attackDamage = source._attackDamage;
  }
  return *this;
}

std::string ClapTrap::getName(void) const { return this->_name; }

int ClapTrap::getHitPoints(void) const { return this->_hitPoints; }

int ClapTrap::getEnergyPoints(void) const { return this->_energyPoints; }

int ClapTrap::getAttackDamage(void) const { return this->_attackDamage; }

void ClapTrap::setName(std::string name) { this->_name = name; }

void ClapTrap::setHitPoints(int hitPoints) { this->_hitPoints = hitPoints; }

void ClapTrap::setEnergyPoints(int energyPoints) {
  this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage) {
  this->_attackDamage = attackDamage;
}

void ClapTrap::attack(std::string const& target) {
  if (this->_hitPoints <= 0) {
    std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
    return;
  }
  if (this->_energyPoints <= 0) {
    std::cout << "ClapTrap " << this->_name << " is without energy points!"
              << std::endl;
  } else {
    std::cout << "ClapTrap " << this->_name << " attacks " << target
              << ", causing " << this->_attackDamage << " points of damage!"
              << std::endl;
    this->_energyPoints--;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints <= 0) {
    std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
    return;
  }
  if ((int)amount >= this->_hitPoints) {
    std::cout << "ClapTrap " << this->_name << " takes " << amount
              << " and dies!" << std::endl;
  } else {
    std::cout << "ClapTrap " << this->_name << " takes " << amount
              << " points of damage!" << std::endl;
  }
  this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->_hitPoints <= 0 || this->_energyPoints <= 0) {
    std::cout << "ClapTrap " << this->_name << " is dead or without energy!"
              << std::endl;
    return;
  }
  this->_hitPoints += amount;
  std::cout << "ClapTrap " << this->_name << " is repaired " << amount
            << " points of damage!" << std::endl;
  this->_energyPoints--;
}
