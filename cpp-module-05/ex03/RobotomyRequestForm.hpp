/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:57:32 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/07 21:49:40 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  std::string _target;

 protected:
  void _execute(void) const;

 public:
  RobotomyRequestForm();                           // Default constructor
  RobotomyRequestForm(std::string const& target);  // Parameter constructor
  RobotomyRequestForm(
      RobotomyRequestForm const& other);  // Copy constructor
  virtual ~RobotomyRequestForm();                         // Destructor

  RobotomyRequestForm& operator=(
      RobotomyRequestForm const& other);  // Copy assignment operator

  // Getters
  std::string getTarget() const;
};

#endif  // ROBOTOMYREQUESTFORM_HPP
