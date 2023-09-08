/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:57:17 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/07 21:49:51 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  std::string _target;

 protected:
  void _execute(void) const;

 public:
  PresidentialPardonForm();                           // Default constructor
  PresidentialPardonForm(std::string const& target);  // Parameter constructor
  PresidentialPardonForm(
      PresidentialPardonForm const& other);           // Copy constructor
  virtual ~PresidentialPardonForm();                  // Destructor

  PresidentialPardonForm& operator=(
      PresidentialPardonForm const& other);  // Copy assignment operator

  // Getters
  std::string getTarget() const;
};

#endif  // PRESIDENTIALPARDONFORM_HPP
