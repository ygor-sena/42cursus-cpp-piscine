/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:22:51 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/07 18:52:22 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer {
 public:
  Serializer();                         // Default constructor
  Serializer(Serializer const& other);  // Copy constructor
  ~Serializer();                        // Destructor

  Serializer& operator=(Serializer const& other);  // Copy Assignment operator

  // Member functions
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};

#endif  // SERIALIZER_HPP
