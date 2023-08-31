/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:10:32 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/31 10:50:01 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
 private:
  Fixed _x;
  Fixed _y;

 public:
  Point();                               // Default constructor
  ~Point();                              // Destructor
  Point(const Point &point);             // Copy constructor
  Point &operator=(const Point &point);  // Copy assignment operator
  Point(const float x, const float y);
  Fixed const &getX(void) const;
  Fixed const &getY(void) const;
};

// https://www.baeldung.com/cs/check-if-point-is-in-2d-triangle
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif  // POINT_HPP
