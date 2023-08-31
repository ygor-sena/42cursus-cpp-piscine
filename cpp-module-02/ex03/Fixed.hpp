/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:09:47 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/31 14:02:04 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
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
  Fixed(const int value);
  Fixed(const float value);
  float toFloat(void) const;
  int toInt(void) const;

  // Comparison operators
  bool operator>(const Fixed &fixed) const;
  bool operator<(const Fixed &fixed) const;
  bool operator>=(const Fixed &fixed) const;
  bool operator<=(const Fixed &fixed) const;
  bool operator==(const Fixed &fixed) const;
  bool operator!=(const Fixed &fixed) const;

  // Arithmetic operators
  Fixed operator+(const Fixed &fixed) const;
  Fixed operator-(const Fixed &fixed) const;
  Fixed operator*(const Fixed &fixed) const;
  Fixed operator/(const Fixed &fixed) const;

  // Increment and decrement operators
  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);

  // Public overloaded member functions
  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &Fixed);

#endif // FIXED_HPP
