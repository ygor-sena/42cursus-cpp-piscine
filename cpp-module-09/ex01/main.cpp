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
