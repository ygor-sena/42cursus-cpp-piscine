/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:30:08 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/04 15:30:09 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
 public:
  Cat();                  // Default constructor
  Cat(std::string type);  // Parameter constructor
  Cat(const Cat &other);  // Copy constructor
  virtual ~Cat();         // Destructor

  Cat &operator=(const Cat &other);  // Copy assignment operator

  // Member functions
  virtual void makeSound() const;
};

#endif  // CAT_HPP
