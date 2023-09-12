/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:55:11 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/12 10:21:25 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>


class ElementNotFound : public std::exception {
  virtual const char *what() const throw() {
    return ("Element not found in container");
  }
};

template <typename T>
typename T::const_iterator easyfind(T const& container, int const n) {
  typename T::const_iterator it;

  it = std::find(container.begin(), container.end(), n);
  if (it == container.end()) throw ElementNotFound();
  return (it);
}

#endif  // EASYFIND_HPP
