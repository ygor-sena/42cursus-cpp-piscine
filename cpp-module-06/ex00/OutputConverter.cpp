/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OutputConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:55:14 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/08 18:23:25 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OutputConverter.hpp"

OutputConverter::OutputConverter() {}

OutputConverter::OutputConverter(OutputConverter const& src) { *this = src; }

OutputConverter::OutputConverter(char const& conversion) {
  try {
    std::cout << "char: '" << static_cast<char>(conversion) << "'" << std::endl;
  } catch (std::exception& e) {
    std::cerr << "char: " << e.what() << std::endl;
  }
  try {
    std::cout << "int: " << static_cast<int>(conversion) << std::endl;
  } catch (std::exception& e) {
    std::cerr << "int: " << e.what() << std::endl;
  }
  try {
    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(conversion) << "f" << std::endl;
  } catch (std::exception& e) {
    std::cerr << "float: " << e.what() << std::endl;
  }
  try {
    std::cout << "double: " << std::fixed << std::setprecision(1)
              << static_cast<double>(conversion) << std::endl;
  } catch (std::exception& e) {
    std::cerr << "double: " << e.what() << std::endl;
  }
}

OutputConverter::OutputConverter(int const& conversion) {
  try {
    if (conversion == 0) {
      throw ScalarConverter::NonDisplayableException();
    }
    std::cout << "char: '" << static_cast<char>(conversion) << "'" << std::endl;
  } catch (std::exception& e) {
    std::cerr << "char: " << e.what() << std::endl;
  }
  try {
    std::cout << "int: " << static_cast<int>(conversion) << std::endl;
  } catch (std::exception& e) {
    std::cerr << "int: " << e.what() << std::endl;
  }
  try {
    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(conversion) << "f" << std::endl;
  } catch (std::exception& e) {
    std::cerr << "float: " << e.what() << std::endl;
  }
  try {
    std::cout << "double: " << std::fixed << std::setprecision(1)
              << static_cast<double>(conversion) << std::endl;
  } catch (std::exception& e) {
    std::cerr << "double: " << e.what() << std::endl;
  }
}

OutputConverter::OutputConverter(float const& conversion) {
  try {
    if (conversion == 0) {
      throw ScalarConverter::NonDisplayableException();
    }
    std::cout << "char: '" << static_cast<char>(conversion) << "'" << std::endl;
  } catch (std::exception& e) {
    std::cerr << "char: " << e.what() << std::endl;
  }
  try {
    std::cout << "int: " << static_cast<int>(conversion) << std::endl;
  } catch (std::exception& e) {
    std::cerr << "int: " << e.what() << std::endl;
  }
  try {
    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(conversion) << "f" << std::endl;
  } catch (std::exception& e) {
    std::cerr << "float: " << e.what() << std::endl;
  }
  try {
    std::cout << "double: " << std::fixed << std::setprecision(1)
              << static_cast<double>(conversion) << std::endl;
  } catch (std::exception& e) {
    std::cerr << "double: " << e.what() << std::endl;
  }
}

OutputConverter::OutputConverter(double const& conversion) {
  try {
    if (conversion == 0) {
      throw ScalarConverter::NonDisplayableException();
    }
    std::cout << "char: '" << static_cast<char>(conversion) << "'" << std::endl;
  } catch (std::exception& e) {
    std::cerr << "char: " << e.what() << std::endl;
  }
  try {
    std::cout << "int: " << static_cast<int>(conversion) << std::endl;
  } catch (std::exception& e) {
    std::cerr << "int: " << e.what() << std::endl;
  }
  try {
    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(conversion) << "f" << std::endl;
  } catch (std::exception& e) {
    std::cerr << "float: " << e.what() << std::endl;
  }
  try {
    std::cout << "double: " << std::fixed << std::setprecision(1)
              << static_cast<double>(conversion) << std::endl;
  } catch (std::exception& e) {
    std::cerr << "double: " << e.what() << std::endl;
  }
}

OutputConverter::~OutputConverter() {}

OutputConverter& OutputConverter::operator=(OutputConverter const& rhs) {
  if (this != &rhs) {
  }
  return *this;
}
