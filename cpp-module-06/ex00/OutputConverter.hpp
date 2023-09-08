/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OutputConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:55:11 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/08 18:25:18 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUTCONVERTER_HPP
#define OUTPUTCONVERTER_HPP

#include <iomanip>
#include <iostream>
#include <string>

#include "ScalarConverter.hpp"

class OutputConverter {
 public:
  OutputConverter();                            // Default constructor
  OutputConverter(OutputConverter const& src);  // Copy constructor
  OutputConverter(char const& c);               // Char constructor
  OutputConverter(int const& c);                // Int constructor
  OutputConverter(float const& c);              // Float constructor
  OutputConverter(double const& c);             // Double constructor
  ~OutputConverter();                           // Destructor

  OutputConverter& operator=(
      OutputConverter const& rhs);  // Copy Assignment operator
};

#endif  // OUTPUTCONVERTER_HPP
