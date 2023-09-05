/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:31:46 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/04 15:31:47 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat();                       // Default constructor
  WrongCat(std::string type);       // Parameter constructor
  WrongCat(const WrongCat &other);  // Copy constructor
  virtual ~WrongCat();              // Destructor

  WrongCat &operator=(const WrongCat &other);  // Copy assignment operator

  void makeSound() const;
};

#endif  // WRONGCAT_HPP
