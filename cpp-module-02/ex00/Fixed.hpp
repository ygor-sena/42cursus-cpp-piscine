/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:08:56 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/31 14:01:21 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
 private:
  int _rawBits;
  static const int _fractionalBits = 8;

 public:
  Fixed();                               // Default constructor
  Fixed(const Fixed &fixed);             // Copy constructor
  ~Fixed();                              // Destructor
  Fixed &operator=(const Fixed &fixed);  // Copy assignment operator
  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif  // FIXED_HPP
