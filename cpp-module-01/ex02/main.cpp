/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:20:13 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/28 15:35:39 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << GREEN << "Memory Address:" << RESET << std::endl;
  std::cout << std::left << std::setw(11)
            << "str: " << &str << std::endl;
  std::cout << std::left << std::setw(11)
            << "stringPTR: " << stringPTR << std::endl;
  std::cout << std::left << std::setw(11)
            << "stringREF: " << &stringREF << std::endl;

  std::cout << RED << "Memory Content:" << RESET << std::endl;
  std::cout << std::left << std::setw(11)
            << "str: " << str << std::endl;
  std::cout << std::left << std::setw(11)
            << "stringPTR: " << *stringPTR << std::endl;
  std::cout << std::left << std::setw(11)
            << "stringREF: " << stringREF << std::endl;

  return (0);
}