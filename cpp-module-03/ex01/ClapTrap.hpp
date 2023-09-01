/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:18:00 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/01 15:46:57 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
 protected:
  std::string _name;
  int _hitPoints;
  int _energyPoints;
  int _attackDamage;

 public:
  ClapTrap();                                   // Default constructor
  ClapTrap(std::string name);                   // Parameter constructor
  ClapTrap(const ClapTrap& source);             // Copy constructor
  virtual ~ClapTrap();                          // Destructor
  ClapTrap& operator=(const ClapTrap& source);  // Copy assignment operator

  // Getters
  std::string getName(void) const;
  int getHitPoints(void) const;
  int getEnergyPoints(void) const;
  int getAttackDamage(void) const;

  // Setters
  void setName(std::string name);
  void setHitPoints(int hitPoints);
  void setEnergyPoints(int energyPoints);
  void setAttackDamage(int attackDamage);

  // Member functions
  virtual void attack(std::string const& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif  // CLAPTRAP_HPP
