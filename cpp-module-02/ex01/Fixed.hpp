/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:09:08 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/31 10:44:15 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
 private:
  int _rawBits;
  static const int _bitLength = 8;

 public:
  Fixed();                               // Default constructor
  Fixed(const Fixed &fixed);             // Copy constructor
  ~Fixed();                              // Destructor
  Fixed &operator=(const Fixed &fixed);  // Copy assignment operator
  int getRawBits(void) const;
  void setRawBits(int const raw);
  Fixed(const int value);
  Fixed(const float value);
  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &Fixed);

#endif  // FIXED_HPP
