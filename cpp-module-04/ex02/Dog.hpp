/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:31:22 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/04 16:08:22 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
 private:
  Brain *_brain;

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
