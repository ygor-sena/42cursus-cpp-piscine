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

// Path: 42-cpp-modules/cpp-module-09/rex00/Makefile
