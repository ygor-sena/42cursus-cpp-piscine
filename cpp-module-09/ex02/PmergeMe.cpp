/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:39:59 by yde-goes          #+#    #+#             */
/*   Updated: 2024/02/16 16:40:05 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
  *this = src;
  return;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
  if (this != &src) {
    *this = src;
  }
  return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::_list(int quantity, char **input) {
  std::list<int> unsorted;
  std::list<int> sorted;

  clock_t start = clock();
  std::cout << GREEN << "\n[SORTING WITH std::list]" << std::endl;
  for (int i = 1; i < quantity; i++) unsorted.push_back(std::atoi(input[i]));
  std::cout << "Before: ";
  printNumbers(unsorted);
  sorted = _sort(unsorted);
  std::cout << "After: ";
  printNumbers(sorted);
  clock_t end = clock();

  double duration = double(end - start) / CLOCKS_PER_SEC;
  std::cout << "\nTime to process a range of " << sorted.size()
            << " elements with std::list : " << std::fixed
            << std::setprecision(5) << duration << " µs" << RESET << std::endl;
}

void PmergeMe::_vector(int quantity, char **input) {
  std::vector<int> unsorted;
  std::vector<int> sorted;

  clock_t start = clock();
  std::cout << BLUE << "\n[SORTING WITH std::vector]" << std::endl;
  for (int i = 1; i < quantity; i++) unsorted.push_back(std::atoi(input[i]));
  std::cout << "Before: ";
  printNumbers(unsorted);
  sorted = _sort(unsorted);
  std::cout << "After: ";
  printNumbers(sorted);
  clock_t end = clock();

  double duration = double(end - start) / CLOCKS_PER_SEC;
  std::cout << "\nTime to process a range of " << sorted.size()
            << " elements with std::vector : " << std::fixed
            << std::setprecision(5) << duration << " µs" << RESET << std::endl;
}

void PmergeMe::mergeMe(int input_size, char **numbers) {
  _list(input_size, numbers);
  _vector(input_size, numbers);
  return;
}

template <typename T>
void PmergeMe::_sortPairs(T &list, size_t size) {
  if (size <= 1) return;

  T left;
  T right;
  typename T::iterator it = list.begin();

  for (size_t i = 0; i < size / 2; i++) left.push_back(*it++);
  for (size_t i = size / 2; i < size; i++) right.push_back(*it++);

  list.clear();

  _sortPairs(left, left.size());
  _sortPairs(right, right.size());

  while (!right.empty() && !left.empty()) {
    if (left.front().first < right.front().first) {
      list.push_back(left.front());
      left.erase(left.begin());
    } else {
      list.push_back(right.front());
      right.erase(right.begin());
    }
  }

  while (!left.empty()) {
    list.push_back(left.front());
    left.erase(left.begin());
  }

  while (!right.empty()) {
    list.push_back(right.front());
    right.erase(right.begin());
  }
}

template <typename T>
T PmergeMe::_sort(T &list) {
  if (list.size() <= 1) return (list);

  int straggler = -1;
  if (list.size() % 2 != 0) {
    straggler = list.back();
    list.pop_back();
  }

  std::list<std::pair<int, int> > pairs;
  for (typename T::iterator it = list.begin(); it != list.end(); ++it) {
    int first = *it;
    if (++it == list.end()) break;
    int second = *it;
    if (first < second)
      pairs.push_back(std::make_pair(second, first));
    else
      pairs.push_back(std::make_pair(first, second));
  }

  _sortPairs(pairs, pairs.size());

  T sorted;
  T pend;
  for (std::list<std::pair<int, int> >::iterator it = pairs.begin();
       it != pairs.end(); it++) {
    sorted.push_back(it->first);
    pend.push_back(it->second);
  }

  if (straggler != -1) pend.push_back(straggler);

  sorted.insert(sorted.begin(), pend.front());
  T insertSeq = createInsertionOrder<T>(pend.size() - 1);

  if (!insertSeq.empty()) {
    for (typename T::iterator it = insertSeq.begin(); it != insertSeq.end();
         ++it) {
      typename T::iterator itp = pend.begin();
      std::advance(itp, *it);
      typename T::iterator pos =
          std::lower_bound(sorted.begin(), sorted.end(), *itp);
      sorted.insert(pos, *itp);
    }
  }
  return (sorted);
}

int jacobsthal(int n) {
  if (n <= 1) return (n);
  return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}
