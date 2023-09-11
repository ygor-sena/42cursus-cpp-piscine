/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:30:51 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/11 09:30:52 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "iter.hpp"

void multiply(float &i);
void upperCase(std::string &i);

int main(void) {
  {
    int arr[] = {0, 1, 2, 3, 4};
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    iter(arr, arr_len, printArray<int>);
    std::cout << std::endl;
  }
  {
    float arr[] = {0.5f, 1.3f, 2.f, 3.8f, 4.1f};
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    iter(arr, arr_len, multiply);
    iter(arr, arr_len, printArray<float>);
    std::cout << std::endl;
  }
  {
    std::string arr[] = {"Hello", "World", "!"};
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    iter(arr, arr_len, upperCase);
    iter(arr, arr_len, printArray<std::string>);
    std::cout << std::endl;
  }
  return (0);
}

void multiply(float &i) { i *= 2; }

void upperCase(std::string &i) {
  for (size_t j = 0; j < i.length(); j++) {
    i[j] = std::toupper(i[j]);
  }
}
