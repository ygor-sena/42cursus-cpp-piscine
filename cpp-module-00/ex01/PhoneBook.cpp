/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:53:29 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/28 13:53:31 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {
  this->_index = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(Contact contact) {
  int count = 0;

  this->_index++;
  if (this->_index > MAX_ENTRY) {
    for (count = 0; count < MAX_ENTRY - 1; count++) {
      _contacts[count] = _contacts[count + 1];
    }
    _contacts[MAX_ENTRY - 1] = contact;
    this->_index--;
  }
  while (count < MAX_ENTRY) {
    if (_contacts[count].getFirstName() == "") {
      _contacts[count] = contact;
      break;
    }
    count++;
  }
  return;
}

void PhoneBook::searchContact(int index) {
  if (index > MAX_ENTRY || index < 0)
    std::cout << "Invalid index, it must be between 0 and 7." << std::endl;
  else if (_contacts[index].getFirstName() == "" || index > getTotalEntries())
    std::cout << "No contact saved in this index." << std::endl;
  else {
    _printContact(index);
  }
}

void PhoneBook::_printContact(int index)
{
	std::cout << "Selected contact information (" << index
              << "): " << std::endl;
    std::cout << "  First name: " << _contacts[index].getFirstName()
              << std::endl;
    std::cout << "  Last name: " << _contacts[index].getLastName() << std::endl;
    std::cout << "  Nick name: " << _contacts[index].getNickname() << std::endl;
    std::cout << "  Darkest secret: " << _contacts[index].getDarkestSecret()
              << std::endl;
}

void PhoneBook::printPhoneBook() {
  int index = 0;
  _printHeaderList();
  while (index < MAX_ENTRY) {
    if (_contacts[index].getFirstName() != "") {
      std::cout << "|" << std::right << std::setw(10) << index << "|"
                << std::right << std::setw(10)
                << _formatData(_contacts[index].getFirstName()) << "|"
                << std::right << std::setw(10)
                << _formatData(_contacts[index].getLastName()) << "|"
                << std::right << std::setw(10)
                << _formatData(_contacts[index].getNickname()) << "|"
                << std::endl;
    }
    index++;
  }
}

int PhoneBook::getTotalEntries() {
	return this->_index;
}

void PhoneBook::_printHeaderList() {
  std::cout << "|" << std::right << std::setw(10) << "index"
            << "|" << std::right << std::setw(10) << "first name"
            << "|" << std::right << std::setw(10) << "last name"
            << "|" << std::right << std::setw(10) << "nickname"
            << "|" << std::endl;
}

std::string PhoneBook::_formatData(std::string text) {
  if (text.length() > 10) {
    return text.substr(0, 9) + ".";
  } else {
    return std::string(10 - text.length(), ' ') + text;
  }
}
