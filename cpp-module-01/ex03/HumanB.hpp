/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:37:02 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/28 17:27:44 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanB {
 public:
  HumanB(std::string name);
  ~HumanB(void);
  void attack(void);
  void setWeapon(Weapon& type);

 private:
  std::string _name;
  Weapon* _type;
};

#endif
