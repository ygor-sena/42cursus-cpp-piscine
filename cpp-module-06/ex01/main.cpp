/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:14:42 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/07 17:14:26 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

#include "Serializer.hpp"

int main(void) {
  Data data = Data(42);

  uintptr_t raw = Serializer::serialize(&data);
  Data *ptr = Serializer::deserialize(raw);

  std::cout << "Raw pointer: " << &data << std::endl;
  std::cout << "Ptr pointer: " << ptr << std::endl;

  // Why the output of raw is crazy? Because reinterpret_cast treats
  // the given sets of bits as if it had the type given by the new type.
  // Thus, it doesn't do any calculations, which static_cast does.
  // https://stackoverflow.com/questions/573294/when-to-use-reinterpret-cast
  std::cout << "Raw info:    " << std::right << raw << std::endl;

  std::cout << "Data info:   " << data.info << std::endl;
  std::cout << "Ptr info:    " << ptr->info << std::endl;

  return (0);
}
