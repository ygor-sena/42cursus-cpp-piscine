/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:54:00 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/28 14:30:20 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie(void) {
  std::cout << this->_name << " is dead" << std::endl;
}

void Zombie::announce(void) {
  std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
