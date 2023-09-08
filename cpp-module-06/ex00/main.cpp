/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:26:32 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/08 16:59:36 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>

#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
  ScalarConverter sc;

  if (argc != 2) {
    std::cerr << "Wrong number of arguments" << std::endl;
    return (1);
  }
  // td::string value = argv[1];
  try {
    sc.convert(argv[1]);
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  // conver argv[1] to char, int, float and double using static_cast
  /*   std::string literal = argv[1];
    try {
      char c = static_cast<char>(literal);
      std::cout << "char: " << c << std::endl;
    } catch (std::exception& e) {
      std::cerr << "char: impossible" << std::endl;
    }

    try {
      int i = static_cast<int>(literal);
      std::cout << "int: " << i << std::endl;
    } catch (std::exception& e) {
      std::cerr << "int: impossible" << std::endl;
    }

    try {
      float f = static_cast<float>(literal);
      std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f"
                << std::endl;
    } catch (std::exception& e) {
      std::cerr << "float: impossible" << std::endl;
    }

    try {
      double d = static_cast<double>(literal);
      std::cout << "double: " << std::fixed << std::setprecision(1) << d
                << std::endl;
    } catch (std::exception& e) {
      std::cerr << "double: impossible" << std::endl;
    } */

  return 0;
}
