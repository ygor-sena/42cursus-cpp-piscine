/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:26:57 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 13:38:43 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
 private:
  std::string _name;
  AMateria *_inventory[4];

 public:
  Character();                         // Default constructor
  Character(std::string const &name);  // Parameter constructor
  Character(const Character &other);   // Copy constructor
  virtual ~Character();                // Destructor

  Character &operator=(const Character &other);  // Copy assignment operator

  // Member functions
  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
};

#endif  // CHARACTER_HPP
