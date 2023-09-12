/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:42:39 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/12 10:20:25 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "MutantStack.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int main() {
  // Test provided by the subject
  std::cout << GREEN << "*** TEST PROVIDED BY THE SUBJECT ***" << RESET
            << std::endl;
  {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite) {
      std::cout << "[" << *it << "] ";
      ++it;
    }
    std::cout << std::endl << std::endl;
    std::stack<int> s(mstack);
  }
  // List of int
  std::cout << GREEN << "*** LIST OF INT ***" << RESET << std::endl;
  {
    std::list<int> mstack;

    mstack.push_back(5);
    mstack.push_back(17);

    std::cout << "Top: " << mstack.back() << std::endl;

    mstack.pop_back();

    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);

    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite) {
      std::cout << "[" << *it << "] ";
      ++it;
    }
    std::cout << std::endl << std::endl;
  }
  // MutantStack of char
  std::cout << GREEN << "*** MUTANTSTACK OF CHAR ***" << RESET << std::endl;
  {
    MutantStack<char> mstack;

    mstack.push('a');
    mstack.push('b');
    mstack.push('c');
    mstack.push('d');
    mstack.push('e');

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push('f');
    mstack.push('g');
    mstack.push('h');
    mstack.push('i');
    mstack.push('j');

    // ITERATORS
    MutantStack<char>::iterator it = mstack.begin();
    MutantStack<char>::iterator ite = mstack.end();

    ++it;
    --it;
    std::cout << "Iterator: " << std::endl;
    while (it != ite) {
      std::cout << "[" << *it << "] ";
      ++it;
    }
    std::cout << std::endl;

    // CONST ITERATORS
    MutantStack<char>::const_iterator cit = mstack.begin();
    MutantStack<char>::const_iterator cite = mstack.end();

    ++cit;
    --cit;
    std::cout << "Const iterator: " << std::endl;
    while (cit != cite) {
      std::cout << "[" << *cit << "] ";
      ++cit;
    }
    std::cout << std::endl;

    // REVERSE ITERATORS
    MutantStack<char>::reverse_iterator rit = mstack.rbegin();
    MutantStack<char>::reverse_iterator rite = mstack.rend();

    ++rit;
    --rit;
    std::cout << "Reverse iterator: " << std::endl;
    while (rit != rite) {
      std::cout << "[" << *rit << "] ";
      ++rit;
    }
    std::cout << std::endl;

    // CONST REVERSE ITERATORS
    MutantStack<char>::const_reverse_iterator crit = mstack.rbegin();
    MutantStack<char>::const_reverse_iterator crite = mstack.rend();

    ++crit;
    --crit;
    std::cout << "Const reverse iterator: " << std::endl;
    while (crit != crite) {
      std::cout << "[" << *crit << "] ";
      ++crit;
    }
    std::cout << std::endl << std::endl;

    std::stack<char> s(mstack);
  }
  // MutantStack with vector
  std::cout << GREEN << "*** MUTANTSTACK WITH VECTOR ***" << RESET << std::endl;
  {
    MutantStack<double, std::vector<double> > mstack;
    mstack.push(5.2);
    mstack.push(17.5);
    mstack.push(3.3);
    mstack.push(5.5);
    mstack.push(737.7);
    mstack.push(0.0);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size: " << mstack.size() << std::endl;

    MutantStack<double, std::vector<double> >::iterator it = mstack.begin();
    MutantStack<double, std::vector<double> >::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite) {
      std::cout << "[" << *it << "] ";
      ++it;
    }
    std::cout << std::endl;
  }
  return 0;
}
