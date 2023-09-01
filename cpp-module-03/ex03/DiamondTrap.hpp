/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:02:03 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/01 18:16:02 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
 private:
  std::string _name;

 public:
  DiamondTrap();                           // Default constructor
  DiamondTrap(std::string name);           // Parameter constructor
  DiamondTrap(const DiamondTrap& source);  // Copy constructor
  ~DiamondTrap();                          // Destructor
  DiamondTrap& operator=(
      const DiamondTrap& source);          // Copy assignment operator

  // Member functions
  void attack(std::string const& target);
  void whoAmI(void);
};

#endif  // DIAMONDTRAP_HPP
