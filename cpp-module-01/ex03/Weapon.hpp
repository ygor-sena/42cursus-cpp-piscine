/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:27:52 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/28 17:28:21 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
 public:
  Weapon(std::string type);
  ~Weapon(void);
  const std::string& getType(void) const;
  void setType(std::string type);

 private:
  std::string _type;
};

#endif