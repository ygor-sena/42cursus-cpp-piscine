/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:45:57 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/07 21:47:25 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";

void makeUselessInternWorkToTheBone(const std::string &formName,
                                    const std::string &target);

int main(void) {
  Bureaucrat b1 = Bureaucrat("Trash boss Bender", 1);

  makeUselessInternWorkToTheBone("shrubbery creation", b1.getName());
  std::cout << BLUE << "TEST SHRUBBERY CREATION FINISHED" << RESET << std::endl;

  makeUselessInternWorkToTheBone("robotomy request", b1.getName());
  std::cout << BLUE << "TEST ROBOTOMY REQUEST FINISHED" << RESET << std::endl;

  makeUselessInternWorkToTheBone("presidential pardon", b1.getName());
  std::cout << BLUE << "TEST PRESIDENTIAL PARDON FINISHED" << RESET
            << std::endl;

  try {
    makeUselessInternWorkToTheBone("some bullshit form", b1.getName());
  } catch (std::exception &e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }
  std::cout << BLUE << "TEST INVALID FORM FINISHED" << RESET << std::endl;

  return 0;
}

void makeUselessInternWorkToTheBone(const std::string &formName,
                                    const std::string &target) {
  std::cout << BLUE << "*** Trying to make " << formName << " test ***" << RESET
            << std::endl;
  Intern someRandomIntern;
  AForm *rrf;
  rrf = someRandomIntern.makeForm(formName, target);
  rrf->beSigned(Bureaucrat("Bender", 1));
  rrf->execute(Bureaucrat("Bender", 1));

  std::cout << *rrf << std::endl;
  delete rrf;
}
