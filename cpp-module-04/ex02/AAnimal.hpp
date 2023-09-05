/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:30:54 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/04 16:02:16 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
 protected:
  std::string _type;

 public:
  AAnimal();                      // Default constructor
  AAnimal(std::string type);      // Parameter constructor
  AAnimal(const AAnimal &other);  // Copy constructor
  virtual ~AAnimal();             // Destructor

  AAnimal &operator=(const AAnimal &other);  // Copy assignment operator

  // Member functions
  std::string getType() const;
  virtual void makeSound() const = 0;        // Pure virtual function
};

#endif  // ANIMAL_HPP
