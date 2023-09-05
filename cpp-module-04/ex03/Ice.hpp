/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:53:45 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 13:38:22 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
 public:
  Ice();                         // Default constructor
  Ice(std::string const& type);  // Parameter constructor
  Ice(const Ice& other);         // Copy constructor
  virtual ~Ice();                // Destructor

  Ice& operator=(const Ice& other);  // Copy assignment operator

  // Member functions
  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};

#endif  // ICE_HPP
