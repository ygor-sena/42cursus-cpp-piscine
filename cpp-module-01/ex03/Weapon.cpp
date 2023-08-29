/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:46:56 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/28 17:28:37 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) { this->_type = type; }

Weapon::~Weapon(void) {}

const std::string& Weapon::getType(void) const { return (this->_type); }

void Weapon::setType(std::string type) { this->_type = type; }
