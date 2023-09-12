/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:14:37 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/12 10:20:59 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <ostream>
#include <stack>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C> {
 public:
  typedef typename std::stack<T, C>::container_type::iterator iterator;
  typedef
      typename std::stack<T, C>::container_type::const_iterator const_iterator;
  typedef typename std::stack<T, C>::container_type::reverse_iterator
      reverse_iterator;
  typedef typename std::stack<T, C>::container_type::const_reverse_iterator
      const_reverse_iterator;

  MutantStack<T, C>(void) : std::stack<T, C>() {}
  MutantStack<T, C>(MutantStack<T, C> const& src) : std::stack<T, C>(src) {}
  ~MutantStack<T, C>(void) {}

  MutantStack<T, C>& operator=(MutantStack<T, C> const& other) {
    if (this != &other) {
      this->c.clear();
      this->c.insert(this->c.begin(), other.c.begin(), other.c.end());
    }
    return (*this);
  }

  MutantStack<T, C>::iterator begin() { return (this->c.begin()); }

  MutantStack<T, C>::iterator end() { return (this->c.end()); }

  MutantStack<T, C>::const_iterator begin() const { return (this->c.begin()); }

  MutantStack<T, C>::const_iterator end() const { return (this->c.end()); }

  MutantStack<T, C>::reverse_iterator rbegin() { return (this->c.rbegin()); }

  MutantStack<T, C>::reverse_iterator rend() { return (this->c.rend()); }

  MutantStack<T, C>::const_reverse_iterator rbegin() const {
    return (this->c.rbegin());
  }

  MutantStack<T, C>::const_reverse_iterator rend() const {
    return (this->c.rend());
  }
};

#endif  // MUTANTSTACK_HPP
