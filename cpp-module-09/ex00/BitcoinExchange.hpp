/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:40:41 by yde-goes          #+#    #+#             */
/*   Updated: 2024/02/17 15:13:05 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define INPUT_HEADER "date | value"
#define DATABASE_HEADER "date,exchange_rate"
#define DATABASE_PATH "data/data.csv"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

class BitcoinExchange {
 public:
  BitcoinExchange();   // Constructor
  ~BitcoinExchange();  // Destructor
  void readInputFile(std::string filename);

  class FileCouldNotBeOpenedException : public std::exception {
    virtual const char* what() const throw() { return "could not open file."; }
  };

  class InvalidFileHeaderException : public std::exception {
    virtual const char* what() const throw() {
      return "invalid file header format";
    }
  };

  class InvalidDateFormatException : public std::exception {
    virtual const char* what() const throw() { return "invalid date format"; }
  };

  class InvalidExchangeFormatException : public std::exception {
    virtual const char* what() const throw() {
      return "invalid exchange rate value format";
    }
  };

  class BadInputException : public std::exception {
   public:
    BadInputException(std::string line);
    virtual ~BadInputException(void) throw(){};
    virtual const char* what() const throw();

   private:
    std::string _error_message;
  };

  class NegativeRateException : public std::exception {
    virtual const char* what() const throw() {
      return "not a positive number.";
    }
  };

  class OverflowRateException : public std::exception {
    virtual const char* what() const throw() { return "too large a number."; }
  };

 private:
  std::map<std::string, float> _database;

  BitcoinExchange(BitcoinExchange const& src);
  BitcoinExchange& operator=(BitcoinExchange const& src);

  void _loadDatabase(void);
  void _checkDate(std::string line);
  bool _isvalidDate(std::string date);
  bool _isLeapYear(int year);
  void _checkExchangeRate(std::string rate);
  void _trimLine(std::string& line);
  void _outputExchangeCalculus(std::string date, float value);
};

#endif  // BITCOINEXCHANGE_HPP
