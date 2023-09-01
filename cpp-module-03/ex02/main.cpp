/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:54:51 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/01 18:44:20 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";

int main(void) {
  ScavTrap scavtrap("Luffy");
  ScavTrap scavTrap2("Doflamingo");
  ClapTrap* claptrap = &scavtrap;
  FragTrap fragtrap("Usopp");

  // Doflamingo prepares to attack Luffy
  scavTrap2.setAttackDamage(29);

  // Damn! He uses Juroppatsu no Seinaru Kyodan: God Thread
  scavTrap2.attack(scavtrap.getName());
  scavtrap.takeDamage(scavTrap2.getAttackDamage());

  // Luffy's still alive!
  std::cout << GREEN << "Scavtrap Luffy has " << scavtrap.getHitPoints()
            << " hit points! Ganbatte, Luffy!" << RESET << std::endl;

  // Gear... Second!
  scavtrap.setAttackDamage(10);

  // Gomu Gomu no... GATLING GUUUUUUUUUUN!
  for (int i = 0; i < 10; i++) {
    scavtrap.attack(scavTrap2.getName());
    scavTrap2.takeDamage(scavtrap.getAttackDamage());
  }

  // Doflamingo attempts to attack, but he died!
  scavTrap2.attack(scavtrap.getName());

  std::cout << GREEN << "Scavtrap Luffy has " << scavtrap.getHitPoints()
            << " hit points! He can still fight!" << RESET << std::endl;
  std::cout << RED << "Scavtrap Luffy has " << scavtrap.getEnergyPoints()
            << " energy points! He can still attack!" << RESET << std::endl;

  // Luffy won! He recovered himself by eating a lot of meat!
  scavtrap.beRepaired(100);

  // From above, Luffy attacks Doflamingo one more time!
  claptrap->attack(scavTrap2.getName());

  // Usopp was hidden the entire time. He appears as if nothing has happpened
  fragtrap.highFivesGuys();

  // Usopp attacks Doflamingo to make sure he's dead
  fragtrap.attack(scavTrap2.getName());

  return (0);
}
