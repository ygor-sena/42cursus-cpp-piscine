/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:13:25 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/30 15:15:39 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed const ab = (b.getX() - a.getX()) * (point.getY() - a.getY()) -
                   (b.getY() - a.getY()) * (point.getX() - a.getX());
  Fixed const bc = (c.getX() - b.getX()) * (point.getY() - b.getY()) -
                   (c.getY() - b.getY()) * (point.getX() - b.getX());
  Fixed const ca = (a.getX() - c.getX()) * (point.getY() - c.getY()) -
                   (a.getY() - c.getY()) * (point.getX() - c.getX());
  return ((ab > 0 && bc > 0 && ca > 0) || (ab < 0 && bc < 0 && ca < 0));
}
