/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:31:11 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/04 15:31:12 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 private:
  Brain *_brain;

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
