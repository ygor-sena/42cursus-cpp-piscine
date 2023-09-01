/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:54:51 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/01 18:44:08 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";

int main(void) {
  ScavTrap scavTrap("Luffy");
  ScavTrap scavTrap2("Doflamingo");
  ClapTrap* clapTrap = &scavTrap;

  // Doflamingo prepares to attack Luffy
  scavTrap2.setAttackDamage(29);

  // Damn! He uses Juroppatsu no Seinaru Kyodan: God Thread
  scavTrap2.attack(scavTrap.getName());
  scavTrap.takeDamage(scavTrap2.getAttackDamage());

  // Luffy's still alive!
  std::cout << GREEN << "Scavtrap Luffy has " << scavTrap.getHitPoints()
            << " hit points! Ganbatte, Luffy!" << RESET << std::endl;

  // Gear... Second!
  scavTrap.setAttackDamage(10);

  // Gomu Gomu no... GATLING GUUUUUUUUUUN!
  for (int i = 0; i < 10; i++) {
    scavTrap.attack(scavTrap2.getName());
    scavTrap2.takeDamage(scavTrap.getAttackDamage());
  }

  // Doflamingo attempts to attack, but he died!
  scavTrap2.attack(scavTrap.getName());

  std::cout << GREEN << "Scavtrap Luffy has " << scavTrap.getHitPoints()
            << " hit points! He can still fight!" << RESET << std::endl;
  std::cout << RED << "Scavtrap Luffy has " << scavTrap.getEnergyPoints()
            << " energy points! He can still attack!" << RESET << std::endl;

  // Luffy won! He recovered himself by eating a lot of meat!
  scavTrap.beRepaired(100);

  // From above, Luffy attacks Doflamingo one more time!
  clapTrap->attack(scavTrap2.getName());

  return (0);
}
