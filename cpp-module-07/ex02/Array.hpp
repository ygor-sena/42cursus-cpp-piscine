/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:30:45 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/11 09:30:46 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array {
 public:
  Array(void) : _array(NULL), _length(0) {}
  Array(unsigned int n) : _array(new T[n]), _length(n) {}
  Array(Array const& src) : _array(new T[src._length]), _length(src._length) {
    for (size_t i = 0; i < this->_length; i++) {
      this->_array[i] = src._array[i];
    }
  }
  ~Array(void) { delete[] this->_array; }

  Array& operator=(Array const& other) {
    if (this != &other) {
      delete[] this->_array;
      this->_array = new T[other._length];
      this->_length = other._length;
      for (size_t i = 0; i < this->_length; i++) {
        this->_array[i] = other._array[i];
      }
    }
    return (*this);
  }

  T& operator[](unsigned int i) {
    if (i >= this->_length) {
      throw OutOfBoundsException();
    }
    return (this->_array[i]);
  }

  unsigned int size(void) const { return (this->_length); }

  class OutOfBoundsException : public std::exception {
   public:
    virtual const char* what() const throw() { return ("Index out of bounds"); }
  };

 private:
  T* _array;
  unsigned int _length;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Array<T>& arr) {
  os << "[";
  for (size_t i = 0; i < arr.size(); i++) {
    os << arr[i];
    if (i + 1 < arr.size()) {
      os << ", ";
    }
  }
  os << "]";
  return (os);
}

#endif  // ARRAY_HPP
