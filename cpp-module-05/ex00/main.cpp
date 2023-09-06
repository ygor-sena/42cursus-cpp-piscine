/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:45:57 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 14:56:56 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";

int main(void) {
  Bureaucrat b1 = Bureaucrat("b1", 1);
  Bureaucrat b2 = Bureaucrat("b2", 150);

  std::cout << GREEN << b1 << RESET << std::endl;
  std::cout << GREEN << b2 << RESET << std::endl;

  try {
    b1.incrementGrade();

  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }
  
  try {
    b2.decrementGrade();
  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }

  std::cout << GREEN << b1 << RESET << std::endl;
  std::cout << GREEN << b2 << RESET << std::endl;

  return 0;
}
