/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:40:32 by yde-goes          #+#    #+#             */
/*   Updated: 2024/02/17 15:14:46 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << RED << "Usage: ./ex00 [database_file]" << RESET << std::endl;
    return (EXIT_FAILURE);
  }
  try {
    BitcoinExchange exchange;
    exchange.readInputFile(argv[1]);
  } catch (std::exception &e) {
    std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
  }
  return (EXIT_SUCCESS);
}
