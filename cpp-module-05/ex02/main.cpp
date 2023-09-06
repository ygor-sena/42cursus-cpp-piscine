/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:45:57 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/05 19:38:41 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";

void checkBureaucratGrade(Bureaucrat& b1, Bureaucrat& b2);
void checkPresidentialPardonForm(Bureaucrat& b1, Bureaucrat& b2);
void checkRobotomyRequestForm(Bureaucrat& b1, Bureaucrat& b2);
void checkShrubberyCreationForm(Bureaucrat& b1, Bureaucrat& b2);

int main(void) {
  Bureaucrat b1 = Bureaucrat("b1", 1);
  Bureaucrat b2 = Bureaucrat("b2", 144);

  std::cout << GREEN << b1 << RESET << std::endl;
  std::cout << GREEN << b2 << RESET << std::endl;

  checkBureaucratGrade(b1, b2);
  checkPresidentialPardonForm(b1, b2);
  checkRobotomyRequestForm(b1, b2);
  checkShrubberyCreationForm(b1, b2);

  return 0;
}

void checkBureaucratGrade(Bureaucrat& b1, Bureaucrat& b2) {
  std::cout << BLUE << "-- CHECK BUREAUCRAT GRADE --" << RESET << std::endl;
  // Can't increment, because Buraucrat is already at the highest grade
  try {
    b1.incrementGrade();

  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }

  // Can't decrement, because Buraucrat is already at the lowest grade
  try {
    b2.decrementGrade();
  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }

  std::cout << GREEN << b1 << RESET << std::endl;
  std::cout << GREEN << b2 << RESET << std::endl;
  std::cout << BLUE << "-- END CHECK BUREAUCRAT GRADE --" << RESET << std::endl;
}

void checkPresidentialPardonForm(Bureaucrat& b1, Bureaucrat& b2) {
  std::cout << BLUE << "-- CHECK PRESIDENTIAL PARDON FORM --" << RESET
            << std::endl;
  PresidentialPardonForm f1 = PresidentialPardonForm("ppf");

  std::cout << GREEN << f1 << RESET << std::endl;

  // b1 can sign and execute the form because he's the big boss
  try {
    b1.signForm(f1);
    b1.executeForm(f1);
  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }

  // b2 can't sign and execute the form because he hasn't the
  // necessary grade level
  try {
    b2.signForm(f1);
    b2.executeForm(f1);
  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }

  std::cout << GREEN << f1 << RESET << std::endl;
  std::cout << BLUE << "-- END CHECK PRESIDENTIAL PARDON FORM --" << RESET
            << std::endl;
}

void checkRobotomyRequestForm(Bureaucrat& b1, Bureaucrat& b2) {
  std::cout << BLUE << "-- CHECK ROBOTOMY REQUEST FORM --" << RESET
            << std::endl;
  RobotomyRequestForm f1 = RobotomyRequestForm("rrf");

  std::cout << GREEN << f1 << RESET << std::endl;

  // b1 can sign and execute the form because he's the big boss
  try {
    b1.signForm(f1);
    b1.executeForm(f1);
  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }

  // b2 can't sign and execute the form because he hasn't the
  // necessary grade level
  try {
    b2.signForm(f1);
    b2.executeForm(f1);
  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }

  std::cout << GREEN << f1 << RESET << std::endl;
  std::cout << BLUE << "-- END CHECK ROBOTOMY REQUEST FORM --" << RESET
            << std::endl;
}

void checkShrubberyCreationForm(Bureaucrat& b1, Bureaucrat& b2) {
  std::cout << BLUE << "-- CHECK SHRUBBERY CREATION FORM --" << RESET
            << std::endl;
  ShrubberyCreationForm f1 = ShrubberyCreationForm("scf");

  std::cout << GREEN << f1 << RESET << std::endl;

  // b1 can sign and execute the form because he's the big boss
  try {
    b1.signForm(f1);
    b1.executeForm(f1);
  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }

  // b2 can sign the form because he has the necessary grade level
  // but he can't execute because his grade level is too low
  try {
    b2.signForm(f1);
    b2.executeForm(f1);
  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }

  std::cout << GREEN << f1 << RESET << std::endl;
  std::cout << BLUE << "-- END CHECK SHRUBBERY CREATION FORM --" << RESET
            << std::endl;
}