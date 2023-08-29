/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:41:19 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/28 14:53:41 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
  Zombie* horde = new Zombie[N];
  for (int i = 0; i < N; i++) {
    horde[i].setName(name);
  }
  return (horde);
}
