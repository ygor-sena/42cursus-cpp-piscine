/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:13:11 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/25 16:40:52 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_ENTRY 8

class PhoneBook {
 public:
  PhoneBook();
  ~PhoneBook();
  void addContact(Contact contact);
  void searchContact(int index);
  void printPhoneBook();
  int getTotalEntries();

 private:
  Contact _contacts[MAX_ENTRY];
  int _index;
  void _printHeaderList();
  void _printContact(int index);
  std::string _formatData(std::string text);
};

#endif  // PHONEBOOK_HPP
