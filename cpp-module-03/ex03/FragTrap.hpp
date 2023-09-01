/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:49:42 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/01 18:25:52 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 public:
  FragTrap();                                   // Default constructor
  FragTrap(std::string name);                   // Parameter constructor
  FragTrap(const FragTrap& source);             // Copy constructor
  ~FragTrap();                                  // Destructor
  FragTrap& operator=(const FragTrap& source);  // Copy assignment operator

  // Member functions
  void attack(std::string const& target);
  void highFivesGuys(void);
};

#endif  // FRAGTRAP_HPP
