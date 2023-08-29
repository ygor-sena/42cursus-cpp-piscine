/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:19:28 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/29 13:36:27 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::_debug(void) {
  std::cout
      << "[DEBUG]\nI love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n"
      << std::endl;
}

void Harl::_info(void) {
  std::cout
      << "[INFO]\nI cannot believe adding extra bacon cost more money. You "
         "didn't "
         "put enough bacon in my burger! If you did, I wouldn't be asking for "
         "more!\n"
      << std::endl;
}

void Harl::_warning(void) {
  std::cout
      << "[WARNING]\nI think I deserve to have some extra bacon for free. I've "
         "been coming for years whereas you just started working here "
         "since last month.\n"
      << std::endl;
}

void Harl::_error(void) {
  std::cout
      << "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n"
      << std::endl;
}

void Harl::complain(std::string level) {
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  void (Harl::*f[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning,
                              &Harl::_error};
  for (int i = 0; i < 4; i++) {
    if (levels[i].compare(level))
      (this->*f[i])();
  }
}

