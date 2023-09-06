/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:57:32 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 18:31:16 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
 private:
  std::string _target;

 public:
  RobotomyRequestForm();                           // Default constructor
  RobotomyRequestForm(std::string const& target);  // Parameter constructor
  RobotomyRequestForm(RobotomyRequestForm const& other);  // Copy constructor
  virtual ~RobotomyRequestForm();                                 // Destructor

  RobotomyRequestForm& operator=(
      RobotomyRequestForm const& other);  // Copy assignment operator

  // Getters
  std::string getTarget() const;

  // Member functions
  void execute(Bureaucrat const& executor) const;
};

#endif  // ROBOTOMYREQUESTFORM_HPP
