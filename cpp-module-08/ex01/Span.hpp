/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:03:25 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/12 10:21:11 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <numeric>
#include <vector>

class Span {
 private:
  std::vector<int> _container;
  unsigned int _storeSize;

 public:
  Span();                 // Default constructor
  Span(unsigned int n);   // Parameter constructor
  Span(Span const& src);  // Copy constructor
  ~Span();                // Destructor

  Span& operator=(Span const& other);  // Copy assignment operator

  std::vector<int> const& getSize(void) const;
  void addNumber(int n);
  unsigned int shortestSpan(void) const;
  unsigned int longestSpan(void) const;

  template <typename T>
  void addNumberRange(typename T::iterator& begin, typename T::iterator& end) {
    if (this->_container.size() + std::distance(begin, end) > this->_storeSize)
      throw FullContainerException();
    this->_container.insert(this->_container.end(), begin, end);
  }

  class FullContainerException : public std::exception {
    virtual const char* what() const throw() {
      return ("Container is full. Can't add a new element");
    }
  };

  class SpanNotFoundException : public std::exception {
    virtual const char* what() const throw() {
      return ("Container is either empty or has only one element");
    }
  };
};

std::ostream& operator<<(std::ostream& os, Span const& span);

#endif  // SPAN_HPP
