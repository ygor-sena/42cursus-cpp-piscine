/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:45:25 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/29 14:30:52 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
  Zombie* horde;
  int N;

  N = 10;
  std::cout << GREEN << "Creating a horde of zombies" << std::endl;
  horde = zombieHorde(N, "Zombie");
  std::cout << GREEN << "Announcing the horde of zombies" << RESET << std::endl;
  for (int i = 0; i < N; i++)
   horde[i].announce();
  std::cout << RED << "Killing the horde of zombies" << RESET << std::endl;
  delete[] horde;

  return (0);
}