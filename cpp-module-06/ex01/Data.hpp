/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:58:57 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/07 16:54:32 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

struct Data {
  int info;

  Data();                              // Default constructor
  Data(int input);                     // Parameter constructor
  Data(Data const& other);             // Copy constructor
  Data& operator=(Data const& other);  // Copy Assignment operator
  ~Data();                             // Destructor
};

#endif  // DATA_HPP
