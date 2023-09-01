/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:18:08 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/01 18:44:31 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";

int main(void) {
  ClapTrap clapTrap("Luffy");
  ClapTrap clapTrap2("Doflamingo");

  // Doflamingo prepares to attack Luffy
  clapTrap2.setAttackDamage(9);

  // Damn! He uses Juroppatsu no Seinaru Kyodan: God Thread
  clapTrap2.attack(clapTrap.getName());
  clapTrap.takeDamage(clapTrap2.getAttackDamage());

  // Luffy's still alive!
  std::cout << GREEN << "Claptrap Luffy has " << clapTrap.getHitPoints()
            << " hit points! Ganbatte, Luffy!" << RESET << std::endl;

  // Gear... Second!
  clapTrap.setAttackDamage(1);

  // Gomu Gomu no... GATLING GUUUUUUUUUUN!
  for (int i = 0; i < 10; i++) {
    clapTrap.attack(clapTrap2.getName());
    clapTrap2.takeDamage(clapTrap.getAttackDamage());
  }

  // Doflamingo attempts to attack, but he died!
  clapTrap2.attack(clapTrap.getName());

  std::cout << GREEN << "Claptrap Luffy has " << clapTrap.getHitPoints()
            << " hit points! He can still fight!" << RESET << std::endl;
  std::cout << RED << "Claptrap Luffy has " << clapTrap.getEnergyPoints()
            << " energy points! He's exhausted and can't attack anymore."
            << RESET << std::endl;

  // Luffy won! But he's tired and will sleep a little!
  clapTrap.beRepaired(100);

  return (0);
}
