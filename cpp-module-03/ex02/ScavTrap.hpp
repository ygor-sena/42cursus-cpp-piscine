/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:55:18 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/01 18:25:27 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  ScavTrap();                                   // Default constructor
  ScavTrap(std::string name);                   // Parameter constructor
  ScavTrap(const ScavTrap& source);             // Copy constructor
  ~ScavTrap();                                  // Destructor
  ScavTrap& operator=(const ScavTrap& source);  // Copy assignment operator

  // Member functions
  void attack(std::string const& target);
  void guardGate(void);
};

#endif  // SCAVTRAP_HPP
