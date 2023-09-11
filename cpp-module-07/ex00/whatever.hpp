/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:31:11 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/11 09:31:12 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
T const& min(T const& a, T const& b) {
  return (a < b ? a : b);
}

template <typename T>
T const& max(T const& a, T const& b) {
  return (a > b ? a : b);
}

#endif  // WHATEVER_HPP
