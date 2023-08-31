/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:10:29 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/30 15:27:19 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::~Point() {}

Point::Point(const Point &point) : _x(point._x), _y(point._y) {}

Point &Point::operator=(const Point &point) {
  if (this != &point) {
	this->_x = point._x;
	this->_y = point._y;
  }
  return (*this);
}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Fixed const &Point::getX(void) const { return (this->_x); }

Fixed const &Point::getY(void) const { return (this->_y); }
