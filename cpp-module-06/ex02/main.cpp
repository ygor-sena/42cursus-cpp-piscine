/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:33:22 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/07 18:57:41 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void) {
  // Use current time as seed for random generator
  std::srand(std::time(NULL));

  Base *base = generate();
  Base *base2 = NULL;
  identify(base);
  identify(*base);

  // https://cplusplus.com/doc/tutorial/typecasting/
  // https://www.bogotobogo.com/cplusplus/dynamic_cast.php
  // dynamic_cast returns NULL (nullptr) if the POINTER cast fails
  identify(base2);

  // dynamic_cast throws an exception if the REFERENCE cast fails
  identify(*base2);

  delete base;

  return (0);
}
