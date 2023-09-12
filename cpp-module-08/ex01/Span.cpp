/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:30:35 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/12 10:21:15 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _container(), _storeSize(0) {}

Span::Span(unsigned int n) : _container(), _storeSize(n) {}

Span::Span(Span const& src) { *this = src; }

Span::~Span() {}

Span& Span::operator=(Span const& other) {
  if (this != &other) {
    this->_container.clear();
    this->_container.insert(this->_container.begin(), other._container.begin(),
                            other._container.end());
    this->_storeSize = other._storeSize;
  }
  return (*this);
}

void Span::addNumber(int n) {
  if (this->_container.size() == this->_storeSize)
    throw FullContainerException();
  this->_container.push_back(n);
}

unsigned int Span::shortestSpan(void) const {
  if (this->_container.size() <= 1) {
    throw SpanNotFoundException();
  }

  std::vector<int> sorted(this->_container);
  std::sort(sorted.begin(), sorted.end());

  std::vector<int> span(sorted);
  std::adjacent_difference(sorted.begin(), sorted.end(), span.begin());

  std::vector<int>::iterator result = std::min_element(span.begin(), span.end());
  return (*result);
}

unsigned int Span::longestSpan(void) const {
  if (this->_container.size() <= 1) {
    throw SpanNotFoundException();
  }

  std::vector<int> sorted(this->_container);
  std::sort(sorted.begin(), sorted.end());

  return (sorted[sorted.size() - 1] - sorted[0]);
}

std::vector<int> const& Span::getSize(void) const { return (this->_container); }

std::ostream& operator<<(std::ostream& os, Span const& span) {
  for (std::vector<int>::const_iterator it = span.getSize().begin();
       it != span.getSize().end(); ++it) {
    os << "[" << *it << "] ";
  }
  return (os);
}
