/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:09:20 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/31 14:02:39 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed(const Fixed &fixed) { *this = fixed; }

Fixed::Fixed(const int value) { this->_rawBits = value << this->_fractionalBits; }

Fixed::Fixed(const float value) {
  this->_rawBits = roundf(value * (1 << this->_fractionalBits));
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &fixed) {
  this->_rawBits = fixed.getRawBits();
  return (*this);
}

int Fixed::getRawBits(void) const { return (this->_rawBits); }

void Fixed::setRawBits(int const raw) { this->_rawBits = raw; }

float Fixed::toFloat(void) const {
  return ((float)this->_rawBits / (float)(1 << this->_fractionalBits));
}

int Fixed::toInt(void) const { return (this->_rawBits >> this->_fractionalBits); }

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return (out);
}

Fixed Fixed::operator+(const Fixed &fixed) const {
  return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) const {
  return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed) const {
  return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const {
  return (Fixed(this->toFloat() / fixed.toFloat()));
}

bool Fixed::operator>(const Fixed &fixed) const {
  return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(const Fixed &fixed) const {
  return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>=(const Fixed &fixed) const {
  return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(const Fixed &fixed) const {
  return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(const Fixed &fixed) const {
  return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(const Fixed &fixed) const {
  return (this->toFloat() != fixed.toFloat());
}

Fixed &Fixed::operator++() {
  this->_rawBits++;
  return (*this);
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  operator++();
  return (tmp);
}

Fixed &Fixed::operator--() {
  this->_rawBits--;
  return (*this);
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  operator--();
  return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b ? a : b); }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b ? a : b); }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return (a > b ? a : b);
}
