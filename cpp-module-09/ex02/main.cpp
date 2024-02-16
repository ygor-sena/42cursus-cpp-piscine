/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:39:39 by yde-goes          #+#    #+#             */
/*   Updated: 2024/02/16 16:40:14 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool validate_input(char **argv);

int main(int argc, char **argv) {
  if (argc <= 2) {
    std::cerr << RED << "Usage: ./PmergeMe [sequence_of_numbers]" << RESET
              << std::endl;
    return (EXIT_FAILURE);
  }
  if (!validate_input(argv)) {
    std::cerr << RED << "Error: the numbers must be unique and of integer type."
              << RESET << std::endl;
    return (EXIT_FAILURE);
  }
  try {
    PmergeMe p;
    p.mergeMe(argc, argv);
  } catch (std::exception &e) {
    std::cerr << RED << e.what() << RESET << std::endl;
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

bool validate_input(char **argv) {
  std::vector<int> numbers;
  for (int i = 1; argv[i]; i++) {
    if (isdigit(argv[i][0]) == 0) {
      return (false);
    }
    int n = std::atoi(argv[i]);
    if (std::find(numbers.begin(), numbers.end(), n) != numbers.end()) {
      return (false);
    }
    numbers.push_back(n);
  }
  return (true);
}
