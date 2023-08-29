/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:19:40 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/29 13:34:04 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static std::string toUpperStr(std::string str);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: ./harl [DEBUG|INFO|WARNING|ERROR]" << std::endl;
    return (1);
  }
  Harl harl;
  std::string level = toUpperStr(argv[1]);
  harl.complain(level);

  return (0);
}

static std::string toUpperStr(std::string str) {
  std::string::iterator it;
  std::string upperStr;
  for (it = str.begin(); it != str.end(); it++) {
    upperStr += (char)std::toupper(*it);
  }
  return (upperStr);
}
