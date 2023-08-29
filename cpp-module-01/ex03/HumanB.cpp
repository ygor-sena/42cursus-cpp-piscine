/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:49:44 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/28 17:28:10 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) { this->_name = name; }

HumanB::~HumanB(void) {}

void HumanB::attack(void) {
  std::cout << this->_name << " attacks with their " << this->_type->getType()
            << std::endl;
}

void HumanB::setWeapon(Weapon& type) { this->_type = &type; }
