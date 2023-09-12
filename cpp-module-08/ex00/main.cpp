/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:02:27 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/12 10:21:22 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <list>
#include <vector>

#include "easyfind.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int main(void) {
  std::vector<int> v;

  std::cout << GREEN << "*** VECTOR ***" << RESET << std::endl;
  for (size_t i = 0; i < 5; i++) {
    v.push_back(i);
  }

  for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << "[" << *it << "] ";
  }
  std::cout << std::endl;

  try {
    std::cout << "Element found: " << *easyfind(v, 3) << std::endl;
    std::cout << "Element found: " << *easyfind(v, 42) << std::endl;
  } catch (std::exception &e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }
  std::cout << std::endl;

  std::list<int> l;

  std::cout << GREEN << "*** LIST ***" << RESET << std::endl;
  for (size_t i = 0; i < 5; i++) {
    l.push_front(i);
  }

  for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
    std::cout << "[" << *it << "] ";
  }
  std::cout << std::endl;

  try {
    std::cout << "Element found: " << *easyfind(l, 4) << std::endl;
    std::cout << "Element found: " << *easyfind(l, 42) << std::endl;
  } catch (std::exception &e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }
  std::cout << std::endl;

  std::deque<int> d;

  std::cout << GREEN << "*** DEQUE ***" << RESET << std::endl;
  for (size_t i = 0; i < 5; i++) {
    d.push_front(i);
  }

  for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it) {
    std::cout << "[" << *it << "] ";
  }
  std::cout << std::endl;

  try {
    std::cout << "Element found: " << *easyfind(d, 1) << std::endl;
    std::cout << "Element found: " << *easyfind(d, 42) << std::endl;
  } catch (std::exception &e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }

  return (0);
}
