/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:10:25 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/31 11:14:50 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";

static void bspMessage(bool result);

int main(void) {
  Point a(0, 0);
  Point b(0, 5);
  Point c(5, 0);
  bool result;

  {
    Point point(1, 1);
    result = bsp(a, b, c, point);
    std::cout << "Case (" << point.getX() << ", " << point.getY()
              << "):" << std::endl;
    bspMessage(result);
  }
  {
    std::cout << "Case (" << 10 << ", " << 10 << "):" << std::endl;
    result = bsp(a, b, c, Point(10, 10));
    bspMessage(result);
  }
  {
    Point point(2, 2);
    std::cout << "Case (" << point.getX() << ", " << point.getY()
              << "):" << std::endl;
    result = bsp(a, b, c, point);
    bspMessage(result);
  }
  {
    Point point(3, 3);
    std::cout << "Case (" << point.getX() << ", " << point.getY()
              << "):" << std::endl;
    result = bsp(a, b, c, Point(3, 3));
    bspMessage(result);
  }
  {
    Point point(2.4, 2.5);
    std::cout << "Case (" << point.getX() << ", " << point.getY()
              << "):" << std::endl;
    result = bsp(a, b, c, Point(2.4, 2.5));
    bspMessage(result);
  }
  {
    Point point(2.6, 2.5);
    std::cout << "Case (" << point.getX() << ", " << point.getY()
              << "):" << std::endl;
    result = bsp(a, b, c, Point(2.6, 2.5));
    bspMessage(result);
  }

  return (0);
}

static void bspMessage(bool result) {
  if (result)
    std::cout << GREEN << "The point is inside the triangle\n"
              << RESET << std::endl;
  else
    std::cout << RED << "The point is outside the triangle\n"
              << RESET << std::endl;
}
