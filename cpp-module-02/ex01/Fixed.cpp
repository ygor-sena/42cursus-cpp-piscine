/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:09:03 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/31 14:02:26 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed::Fixed(const int value) {
  std::cout << "Int constructor called" << std::endl;
  this->_rawBits = value << this->_fractionalBits;
}

Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;
  this->_rawBits = roundf(value * (1 << this->_fractionalBits));
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->_rawBits = fixed.getRawBits();
  return (*this);
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (this->_rawBits);
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->_rawBits = raw;
}

float Fixed::toFloat(void) const {
  return ((float)this->_rawBits / (float)(1 << this->_fractionalBits));
}

int Fixed::toInt(void) const {
  return (this->_rawBits >> this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return (out);
}
