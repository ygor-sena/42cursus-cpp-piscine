/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:27:32 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 13:37:58 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 private:
  AMateria *_inventory[4];

 public:
  MateriaSource();                       // Default constructor
  MateriaSource(const MateriaSource &);  // Copy constructor
  virtual ~MateriaSource();              // Destructor

  MateriaSource &operator=(const MateriaSource &);  // Copy assignment operator

  // Member functions
  void learnMateria(AMateria *);
  AMateria *createMateria(std::string const &type);
};

#endif  // MATERIASOURCE_HPP
