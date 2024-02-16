/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:39:46 by yde-goes          #+#    #+#             */
/*   Updated: 2024/02/16 16:40:10 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[36;1m"
#define RESET "\033[0m"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include <vector>

class PmergeMe {
 private:
  void _list(int size, char **numbers);
  void _vector(int quantity, char **input);

  template <typename T>
  T _sort(T &list);

  template <typename T>
  static void _sortPairs(T &list, size_t size);

 public:
  PmergeMe();
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &src);
  ~PmergeMe();

  void mergeMe(int input_size, char **numbers);
};

int jacobsthal(int n);

template <typename T>
void printNumbers(const T &numbers) {
  typename T::const_iterator it;
  for (it = numbers.begin(); it != numbers.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

template <typename T>
T createInsertionOrder(size_t size) {
  T sequence;

  if (size < 1) return sequence;

  int jacobsthal_it = 2;
  int next = jacobsthal(jacobsthal_it++);

  while (next < static_cast<int>(size)) {
    sequence.push_back(next);
    next = jacobsthal(jacobsthal_it++);
  }

  // Fill in the gaps with decreasing numbers
  next = size;
  while (sequence.size() < size) {
    if (std::find(sequence.begin(), sequence.end(), next) == sequence.end()) {
      sequence.push_back(next);
    }
    next--;
  }

  return sequence;
}

#endif  // PMERGEME_HPP
