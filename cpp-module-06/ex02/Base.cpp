/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:25:01 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/07 18:58:32 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base* generate(void) {
  int choose = std::rand() % 3;

  switch (choose) {
    case 0:
      return (new A());
      break;
    case 1:
      return (new B());
      break;
    case 2:
      return (new C());
    default:
      return (NULL);
  }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p)) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B*>(p)) {
    std::cout << "B" << std::endl;
  } else if (dynamic_cast<C*>(p)) {
    std::cout << "C" << std::endl;
  } else {
	std::cerr << "Unknown type is neither A, B, or C" << std::endl;
  }
}

void identify(Base& p) {
  try {
    A& a = dynamic_cast<A&>(p);
    (void)a;
    std::cout << "A" << std::endl;
  } catch (std::exception& e1) {
    try {
      B& b = dynamic_cast<B&>(p);
      (void)b;
      std::cout << "B" << std::endl;
    } catch (std::exception& e2) {
      try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
      } catch (std::exception& e3) {
        std::cerr << "Unknown type is neither A, B, or C" << std::endl;
      }
    }
  }
}
