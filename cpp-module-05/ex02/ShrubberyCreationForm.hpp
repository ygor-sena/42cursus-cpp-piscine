/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:58:58 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 18:46:08 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  std::string _target;

 public:
  ShrubberyCreationForm();                           // Default constructor
  ShrubberyCreationForm(std::string const& target);  // Parameter constructor
  ShrubberyCreationForm(
      ShrubberyCreationForm const& other);  // Copy constructor
  virtual ~ShrubberyCreationForm();         // Destructor

  ShrubberyCreationForm& operator=(
      ShrubberyCreationForm const& other);  // Copy assignment operator

  // Getters
  std::string getTarget() const;

  // Member functions
  void execute(Bureaucrat const& executor) const;

  // Exceptions
  class FileNotOpenException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

#endif  // SHRUBBERYCREATIONFORM_HPP
