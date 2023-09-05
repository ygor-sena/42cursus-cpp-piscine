/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:31:36 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/04 15:31:37 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
 protected:
  std::string type;

 public:
  WrongAnimal();                          // Default constructor
  WrongAnimal(std::string type);          // Parameter constructor
  WrongAnimal(const WrongAnimal &other);  // Copy constructor
  virtual ~WrongAnimal();                 // Destructor

  WrongAnimal &operator=(const WrongAnimal &other);  // Copy assignment operator

  std::string getType() const;
  void makeSound() const;
};

#endif  // WRONGANIMAL_HPP
