/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:30:32 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/11 09:30:34 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) {
  Array<int> a(5);
  Array<int> b(5);

  for (int i = 0; i < 5; i++) {
    a[i] = i;
    b[i] = i + 42;
  }

  // << operator
  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;

  // [] operator
  std::cout << "a[0]: " << a[0] << std::endl;
  std::cout << "b[0]: " << b[0] << std::endl;

  // Test OutOfBoundsException
  try {
    std::cout << "a[5]: " << a[5] << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  // Test OutOfBoundsException
  try {
    std::cout << "b[5]: " << b[5] << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  // Test copy constructor
  Array<int> c(a);

  std::cout << "c: " << c << std::endl;

  c = b;

  std::cout << "c: " << c << std::endl;

  return 0;
}
