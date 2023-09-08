/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:13:55 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/07 21:42:04 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
  std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
  std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other)
    : AForm(other), _target(other._target) {
  std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
  *this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const& other) {
  std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
  if (this != &other) {
    this->_target = other._target;
  }
  return *this;
}

std::string ShrubberyCreationForm::getTarget() const { return this->_target; }

void ShrubberyCreationForm::_execute(void) const {
    std::ofstream file;

    file.open((this->_target + "_shrubbery").c_str());
    if (!file.is_open()) {
      throw ShrubberyCreationForm::FileNotOpenException();
    }
    file << "                            '.,\n"
         << "                              'b      *\n"
         << "                               '$    #.\n"
         << "                                $:   #:\n"
         << "                                *#  @):\n"
         << "                                :@,@):   ,.**:'\n"
         << "                      ,         :@@*: ..**'\n"
         << "                       '#o.    .:(@'.@*\"\n"
         << "                          'bq,..:,@@*'   ,*\n"
         << "                          ,p$q8,:@)'  .p*'\n"
         << "                         '    '@@Pp@@*'\n"
         << "                               Y7'.'\n"
         << "                              :@):.\n"
         << "                             .:@:'.\n"
         << "                           .::(@:." << std::endl;
    file << std::endl;
    file.close();
}

const char* ShrubberyCreationForm::FileNotOpenException::what() const throw() {
  return ("Error: File not open");
}
