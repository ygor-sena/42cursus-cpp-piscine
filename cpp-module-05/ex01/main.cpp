/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:45:57 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 16:51:33 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";

int main(void) {
  Bureaucrat b1 = Bureaucrat("b1", 1);
  Bureaucrat b2 = Bureaucrat("b2", 150);

  std::cout << GREEN << b1 << RESET << std::endl;
  std::cout << GREEN << b2 << RESET << std::endl;

  // Can't increment, because Buraucrat is already at the highest grade
  try {
    b1.incrementGrade();

  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }

  // Can't decrement, because Buraucrat is already at the lowest grade
  try {
    b2.decrementGrade();
  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }

  std::cout << GREEN << b1 << RESET << std::endl;
  std::cout << GREEN << b2 << RESET << std::endl;

  std::cout << "---------------------" << std::endl;
  Form f1 = Form("f1", 1, 1);
  Form f2 = Form("f2", 150, 150);

  std::cout << GREEN << f1 << RESET << std::endl;
  std::cout << GREEN << f2 << RESET << std::endl;

  // b2 can't sign the form because he's not the big boss
  try {
    b1.signForm(f1);
  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }

  // b2 can sign the form because he has the necessary grade level
  try {
    b2.signForm(f1);
  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }

  std::cout << GREEN << f1 << RESET << std::endl;
  std::cout << GREEN << f2 << RESET << std::endl;

  return 0;
}
