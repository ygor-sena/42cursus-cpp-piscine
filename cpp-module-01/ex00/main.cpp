/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:53:51 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/28 15:14:22 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>

#include "Zombie.hpp"

int main(void) {
  std::cout << RED << "------------------------------------" << RESET
            << std::endl;
  std::cout << RED << "Creating a zombie on the stack" << RESET << std::endl;

  Zombie* zombieStack = new Zombie("Stacker Zombie");
  zombieStack->announce();
  delete zombieStack;

  std::cout << RED << "------------------------------------" << RESET
            << std::endl;
  std::cout << GREEN << "------------------------------------" << RESET
            << std::endl;
  std::cout << GREEN << "Creating a zombie on the heap" << RESET << std::endl;

  randomChump("Heaper Zombie");

  std::cout << GREEN << "------------------------------------" << RESET
            << std::endl;

  return (0);
}