#include "BitcoinExchange.hpp"

// Constructor
BitcoinExchange::BitcoinExchange() {
	_loadDatabase();
	return ;
}

// Destructor
BitcoinExchange::~BitcoinExchange() { return; }

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) { *this = src; }

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src) {
    if (this != &src)
        *this = src;
    return (*this);
}

void BitcoinExchange::_loadDatabase(void) {
  std::ifstream file("data/data.csv");
  std::string line;
  std::string date;
  std::string value;

  if (!file.is_open()) {
	throw FileCouldNotBeOpenedException();
  }
  std::getline(file, line);
  if (line != HEADER_DATABASE)
	throw InvalidFileHeaderException();
  while (std::getline(file, line)) {
	date = line.substr(0, line.find(','));
	value = line.substr(line.find(',') + 1);
	this->_database[date] = std::atof(value.c_str());
  }
  file.close();
}

// Member functions
void BitcoinExchange::readInputFile(std::string filename) {
  std::ifstream file(filename.c_str());
  std::string line;
  std::string date;
  std::string value;

  if (!file.is_open()) {
    throw FileCouldNotBeOpenedException();
  }
  std::getline(file, line);
  if (line != HEADER_FILE)
    throw InvalidFileHeaderException();
  while (std::getline(file, line)) {
    try {
	  date = line.substr(0, line.find('|'));
	  value = line.substr(line.find('|') + 1);
      _checkDate(date);
      _checkExchangeRate(value);
    } catch (std::exception &e) {
      std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
      continue;
    }
    _outputExchangeCalculus(date, std::atof(value.c_str()));
  }
  file.close();
}

void BitcoinExchange::_outputExchangeCalculus(std::string date, float value) {
    std::map<std::string, float>::iterator it = this->_database.find(date);
    float closest_value = 0;

    if (it != this->_database.end()) {
      std::cout << GREEN << date << " => " << value << " = " << value * it->second << RESET << std::endl;
      return ;
    }
    for (it = this->_database.begin(); it != this->_database.end(); it++) {
      if (it->first > date)
          break ;
      closest_value = it->second;
    }
    std::cout << GREEN << date << " => " << value << " = " << value * closest_value << RESET << std::endl;
}

void BitcoinExchange::_checkExchangeRate(std::string rate) {
  _trimLine(rate);
  if (!rate.length() || rate.find_first_not_of("0123456789.") != std::string::npos) {
    throw BadInputException(rate);
  }
  if (std::atof(rate.c_str()) < 0) {
    throw NegativeRateException();
  } else if (std::atof(rate.c_str()) > 1000) {
    throw OverflowRateException();
  }
}

void BitcoinExchange::_trimLine(std::string &line) {
  size_t start = line.find_first_not_of(" \t\r\n");
  size_t end = line.find_last_not_of(" \t\r\n");
  if (start == std::string::npos)
    line = "";
  else
    line = line.substr(start, end - start + 1);  
}

void BitcoinExchange::_checkDate(std::string line) {
  _trimLine(line);
  if (!line.length() || !_isvalidDate(line)) {
    throw BadInputException(line);
  }
}

bool BitcoinExchange::_isvalidDate(std::string date) {
  const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  if (date.length() != 10) {
    return (false);
  }
  for (int i = 0; i < 10; i++) {
    if ((i == 4 || i == 7)) {
      if (date[i] != '-') {
        return (false);
      }
    }
    else if (!std::isdigit(date[i])) {
      return (false);
    }
  }
  
  int year = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());
  
  if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
    return (false);
  }
  if (month == 2) {
    if (_isLeapYear(year)) {
      return (day <= 29);
    }
  }

  return (day <= daysInMonth[month]);
}

bool BitcoinExchange::_isLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

const char *BitcoinExchange::BadInputException::what() const throw() {
  return (_error_message.c_str());
}

BitcoinExchange::BadInputException::BadInputException(std::string line) {
  _error_message = "bad input => " + line;
}
