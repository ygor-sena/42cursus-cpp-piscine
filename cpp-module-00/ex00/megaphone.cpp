/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:02:54 by yde-goes          #+#    #+#             */
/*   Updated: 2023/06/30 14:42:49 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[]) {
  if (argc <= 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  for (int i = 1; i < argc; i++) {
    for (int j = 0; argv[i][j]; j++) {
      std::cout << (char)std::toupper(argv[i][j]);
    }
  }
  std::cout << std::endl;
  return (0);
}