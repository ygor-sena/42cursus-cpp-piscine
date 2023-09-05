/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:36:13 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 13:38:33 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
 public:
  Cure();                         // Default constructor
  Cure(std::string const& type);  // Parameter constructor
  Cure(const Cure& other);        // Copy constructor
  virtual ~Cure();                // Destructor

  Cure& operator=(const Cure& other);  // Copy assignment operator

  // Member functions
  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};

#endif  // CURE_HPP
