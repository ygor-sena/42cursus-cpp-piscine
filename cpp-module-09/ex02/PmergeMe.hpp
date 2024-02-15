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

  template <typename Container>
  static void _sortPairs(Container &list, size_t size);

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

  if (size < 1) {
    return (sequence);
  }

  int jacobsthal_it = 2;
  int next = jacobsthal(jacobsthal_it++);
  sequence.push_back(next);

  while (sequence.size() < size) {
    next = jacobsthal(jacobsthal_it++);
    if (next >= static_cast<int>(size)) {
      next = size;
    }
    while (sequence.size() < size && next > 0) {
      sequence.push_back(next);
      if (std::find(sequence.begin(), sequence.end(), next - 1) !=
          sequence.end()) {
        break;
      }
      next--;
    }
  }
  return (sequence);
}

#endif  // PMERGEME_HPP
