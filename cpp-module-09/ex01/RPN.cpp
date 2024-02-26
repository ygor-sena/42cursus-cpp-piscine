/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:41:24 by yde-goes          #+#    #+#             */
/*   Updated: 2024/02/16 16:41:28 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &src) { *this = src; }

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &src) {
  if (this != &src) {
    this->_tokens = src._tokens;
  }
  return (*this);
}

bool RPN::_isOperator(std::string token) {
  return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::_isAllowedNumber(std::string token) {
  double nbr;
  for (size_t i = 0; i < token.length(); i++) {
    if (!isdigit(token[i])) {
      return (false);
    }
  }

  try {
    nbr = std::strtod(token.c_str(), NULL);
  } catch (std::exception &e) {
    throw RPN::RPNException("Error: token is not a valid number.");
  }

  if (nbr < 0 || nbr > 9) {
    throw RPN::RPNException("Error: number must be between 0 and 9.");
  }
  return (true);
}

double RPN::calculateRPN(std::string expression) {
  std::string token;
  std::istringstream iss(expression);

  if (expression.find_first_not_of("0123456789 +-*/") != std::string::npos) {
    throw RPN::RPNException("Error: invalid character in expression.");
  }
  while (iss >> token) {
    if (this->_isAllowedNumber(token))
      this->_tokens.push(std::strtod(token.c_str(), NULL));
    else if (this->_isOperator(token))
      this->_performOperation(token[0]);
  }
  if (this->_tokens.size() != 1) {
    throw RPN::RPNException(
        "Error: not enough operators to perform operation.");
  }
  return (this->_tokens.top());
}

void RPN::_performOperation(char token) {
  double a, b;

  if (this->_tokens.size() < 2) {
    throw RPN::RPNException("Error: not enough numbers to perform operation.");
  }
  b = this->_tokens.top();
  this->_tokens.pop();
  a = this->_tokens.top();
  this->_tokens.pop();
  switch (token) {
    case '+':
      this->_tokens.push(a + b);
      break;
    case '-':
      this->_tokens.push(a - b);
      break;
    case '*':
      this->_tokens.push(a * b);
      break;
    case '/':
      if (b == 0) {
        throw RPN::RPNException("Error: division by zero.");
      }
      this->_tokens.push(a / b);
      break;
  }
}

RPN::RPNException::RPNException(std::string const &message)
    : _errorMessage(message) {}

RPN::RPNException::~RPNException() throw() {}

const char *RPN::RPNException::what() const throw() {
  return (this->_errorMessage.c_str());
}
