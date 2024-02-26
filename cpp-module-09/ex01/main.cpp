/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:41:31 by yde-goes          #+#    #+#             */
/*   Updated: 2024/02/16 16:41:36 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << RED << "Usage: ./RPN \"[expression]\"" << RESET << std::endl;
    return (EXIT_FAILURE);
  }
  RPN rpn;
  try {
    std::cout << GREEN << rpn.calculateRPN(argv[1]) << RESET << std::endl;
  } catch (RPN::RPNException &e) {
    std::cerr << RED << e.what() << RESET << std::endl;
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
