/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:31:03 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/04 16:05:31 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
 private:
  std::string _ideas[100];

 public:
  Brain();                    // Default constructor
  Brain(const Brain &other);  // Copy constructor
  virtual ~Brain();           // Destructor

  Brain &operator=(const Brain &other);  // Copy assignment operator

  // Member functions
  std::string getIdea(int index) const;
  void setIdea(int index, std::string idea);
};

#endif  // BRAIN_HPP
