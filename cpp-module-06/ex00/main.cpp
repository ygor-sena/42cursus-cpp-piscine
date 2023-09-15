/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:26:32 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/08 18:52:39 by yde-goes         ###   ########.fr       */
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

  try {
    sc.convert(argv[1]);
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
