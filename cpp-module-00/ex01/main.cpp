/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:08:26 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/25 23:13:53 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <iostream>
#include "PhoneBook.hpp"

std::string strToUpper(std::string str);
bool hasLetter(std::string str);

int main(void) {
  PhoneBook phoneBook;
  Contact contact;
  std::string userInput;

  std::cout << "Welcome to the C++ phoneBook!" << std::endl;
  while (strToUpper(userInput).compare("EXIT")) {
    std::cout << "What do you want to do? The actions are: ADD, SEARCH or EXIT"
              << std::endl;
    getline(std::cin, userInput);
    if (!strToUpper(userInput).compare("ADD")) {
      do {
        std::cout << "First name: " << std::endl;
        getline(std::cin, userInput);
        contact.setFirstName(userInput);
      } while (contact.getFirstName().empty());
      do {
        std::cout << "Last name: " << std::endl;
        getline(std::cin, userInput);
        contact.setLastName(userInput);
      } while (contact.getLastName().empty());
      do {
        std::cout << "Nickname: " << std::endl;
        getline(std::cin, userInput);
        contact.setNickname(userInput);
      } while (contact.getNickname().empty());
      do {
        std::cout << "Darkest secret: " << std::endl;
        getline(std::cin, userInput);
        contact.setDarkestSecret(userInput);
      } while (contact.getDarkestSecret().empty());
      do {
        std::cout << "Phone number: " << std::endl;
        getline(std::cin, userInput);
        contact.setPhoneNumber(userInput);
      } while (contact.getPhoneNumber().empty());

      phoneBook.addContact(contact);
    }
    if (!strToUpper(userInput).compare("SEARCH")) {
      phoneBook.printPhoneBook();
      if (phoneBook.getTotalEntries() > 0) {
        std::cout << "Select a contact index (0-7): " << std::endl;
        do {
          getline(std::cin, userInput);
          if (!hasLetter(userInput))
            phoneBook.searchContact(atoi(userInput.c_str()));
          else
            std::cout << "The index must be a number between 0 and 7."
                      << std::endl;
        } while (hasLetter(userInput));
      }
    }
  }
  return (0);
}

std::string strToUpper(std::string str) {
  for (int i = 0; str[i]; i++) {
    str[i] = std::toupper(str[i]);
  }
  return (str);
}

bool hasLetter(std::string str) {
  for (int i = 0; str[i]; i++) {
    if (std::isalpha(str[i])) {
      return (true);
    }
  }
  return (false);
}
