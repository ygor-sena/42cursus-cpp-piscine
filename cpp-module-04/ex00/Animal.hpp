/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:30:00 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/04 16:00:28 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
 protected:
  std::string _type;

 public:
  Animal();                     // Default constructor
  Animal(std::string type);     // Parameter constructor
  Animal(const Animal &other);  // Copy constructor
  virtual ~Animal();            // Destructor

  Animal &operator=(const Animal &other);  // Copy assignment operator

  // Member functions
  std::string getType() const;
  virtual void makeSound() const;
};

#endif  // ANIMAL_HPP
