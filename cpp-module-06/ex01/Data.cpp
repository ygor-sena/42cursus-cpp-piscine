/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:58:59 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/07 16:55:03 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : info(0) {}

Data::Data(int input) : info(input) {}

Data::Data(Data const& other) { *this = other; }

Data::~Data() {}

Data& Data::operator=(Data const& other) {
  if (this != &other) {
    this->info = other.info;
  }
  return *this;
}
