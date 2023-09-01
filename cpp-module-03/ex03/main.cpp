/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:54:51 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/01 18:32:08 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";

int main(void) {
  DiamondTrap diamondTrap("Franky");

  // Franky, our SUUUUPER robot appears!
  std::cout << "Franky hit points: " << diamondTrap.getHitPoints() << std::endl;
  std::cout << "Franky energy points: " << diamondTrap.getEnergyPoints()
            << std::endl;
  std::cout << "Franky atk damage: " << diamondTrap.getAttackDamage()
            << std::endl;

  // FRANKY RADICAL BEEEEEEEEEEEEEAAAAAAMMMMMMMMMMM
  diamondTrap.attack("the sky");

  // Franky's catchphrases
  diamondTrap.guardGate();
  diamondTrap.whoAmI();

  return (0);
}
