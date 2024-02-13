#ifndef RPN_HPP
#define RPN_HPP

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stack>
#include <string>

class RPN {
 public:
  RPN();
  RPN(RPN const &src);
  ~RPN();
  RPN &operator=(const RPN &src);
  double calculateRPN(std::string expression);

  class RPNException : public std::exception {
   public:
    RPNException(std::string const &message);
    virtual ~RPNException() throw();
    virtual const char *what() const throw();

   private:
    std::string _errorMessage;
  };

 private:
  std::stack<double> _tokens;
  bool _isOperator(std::string token);
  bool _isAllowedNumber(std::string token);
  void _performOperation(char token);
};

#endif  // RPN_HPP
