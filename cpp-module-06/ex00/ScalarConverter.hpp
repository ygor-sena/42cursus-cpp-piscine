/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:30:38 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/08 18:05:43 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <ctype.h>
#include <stdlib.h>

#include <exception>
#include <iostream>
#include <string>
#include <limits>

#include "OutputConverter.hpp"

enum e_type { NAN, INF, CHAR, INT, FLOAT, DOUBLE };

class ScalarConverter {
 private:
  char _toChar(std::string const& literal);
  int _toInt(std::string const& literal);
  float _toFloat(std::string const& literal);
  double _toDouble(std::string const& literal);

 public:
  ScalarConverter();                            // Default constructor
  ScalarConverter(ScalarConverter const& src);  // Copy constructor
  ~ScalarConverter();                           // Destructor

  ScalarConverter& operator=(
      ScalarConverter const& rhs);  // Copy Assignment operator

  void convert(std::string const& literal);
  void displayError(std::string const& literal);

  // Exceptions
  class ImpossibleConversionException : public std::exception {
    virtual const char* what() const throw() { return "impossible"; }
  };

  class NonDisplayableException : public std::exception {
    virtual const char* what() const throw() { return "Non displayable"; }
  };

  // Validation class
  struct Validation {
   public:
    static int _getInputType(std::string const& literal);
	static bool _isNaN(std::string const& literal);
	static bool _isInf(std::string const& literal);
    static bool _isChar(std::string const& literal);
    static bool _isInt(std::string const& literal);
    static bool _isFloat(std::string const& literal);
    static bool _isDouble(std::string const& literal);

    // Exceptions
    class InvalidInputException : public std::exception {
      virtual const char* what() const throw() {
        return "Invalid input. It must be a char, int, float or double.";
      }
    };
  };
};

#endif  // SCALARCONVERTER_HPP
