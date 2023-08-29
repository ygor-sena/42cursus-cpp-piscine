/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:48:14 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/28 17:27:56 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type) : _name(name), _type(type) {}

void HumanA::attack(void) {
  std::cout << this->_name << " attacks with their " << this->_type.getType()
            << std::endl;
}
