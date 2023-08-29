/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:36:20 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/28 17:28:01 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanA {
 public:
  HumanA(std::string name, Weapon& type);
  void attack(void);

 private:
  std::string _name;
  Weapon& _type;
};

#endif