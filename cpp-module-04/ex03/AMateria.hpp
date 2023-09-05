/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:52:55 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 13:38:52 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class AMateria {
 public:
  AMateria();                         // Default constructor
  AMateria(std::string const& type);  // Parameter constructor
  AMateria(const AMateria& other);    // Copy constructor
  virtual ~AMateria();                // Destructor

  AMateria& operator=(const AMateria& other);  // Copy assignment operator

  std::string const& getType() const;  // Returns the materia type

  // Member functions
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);

 protected:
  std::string _type;
};

#endif  // AMATERIA_HPP
