/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:30:18 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/04 15:30:19 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
 public:
  Dog();                  // Default constructor
  Dog(std::string type);  // Parameter constructor
  Dog(const Dog &other);  // Copy constructor
  virtual ~Dog();         // Destructor

  Dog &operator=(const Dog &other);  // Copy assignment operator

  // Member functions
  virtual void makeSound() const;
};

#endif  // DOG_HPP
