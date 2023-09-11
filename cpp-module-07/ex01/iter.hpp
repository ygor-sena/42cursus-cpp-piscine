/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:30:55 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/11 09:30:56 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ITER_HPP
#define ITER_HPP

template <typename A, typename F>
void iter(A* array, size_t length, F function) {
  for (size_t i = 0; i < length; i++) {
    function(array[i]);
  }
}

template <typename T>
void printArray(T &i) {
  std::cout << i << std::endl;
}

#endif  // ITER_HPP
