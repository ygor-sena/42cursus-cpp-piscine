/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:19:05 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/29 14:34:56 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cout << "Usage: ./ex04 <filename> <string_to_remove> <string_to_insert>" << std::endl;
    return (1);
  }

  Replace replace(argv[1], argv[2], argv[3]);

  return (0);
}
