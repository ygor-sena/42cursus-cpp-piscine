/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:02:54 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/25 16:26:10 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void toUpperStr(std::string str);

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  }
  for (int i = 1; i < argc; i++) {
    std::string str = argv[i];
    toUpperStr(str);
  }
  std::cout << std::endl;
  return (0);
}

static void toUpperStr(std::string str) {
  std::string::iterator it;
  for (it = str.begin(); it != str.end(); it++) {
    std::cout << (char)std::toupper(*it);
  }
}