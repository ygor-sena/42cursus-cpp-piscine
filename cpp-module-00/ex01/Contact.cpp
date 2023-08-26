#include "Contact.hpp"
#include <iostream>

Contact::Contact(void) {
}

Contact::~Contact(void) {
}

std::string Contact::getFirstName(void) {
  return (this->_firstName);
}

std::string Contact::getLastName(void) {
  return (this->_lastName);
}

std::string Contact::getNickname(void) {
  return (this->_nickname);
}

std::string Contact::getDarkestSecret(void) {
  return (this->_darkestSecret);
}

std::string Contact::getPhoneNumber(void) {
  return (this->_phoneNumber);
}

std::string Contact::setFirstName(std::string firstName) {
  this->_firstName = firstName;
  return (this->_firstName);
}

std::string Contact::setLastName(std::string lastName) {
  this->_lastName = lastName;
  return (this->_lastName);
}

std::string Contact::setNickname(std::string nickname) {
  this->_nickname = nickname;
  return (this->_nickname);
}

std::string Contact::setDarkestSecret(std::string darkestSecret) {
  this->_darkestSecret = darkestSecret;
  return (this->_darkestSecret);
}

std::string Contact::setPhoneNumber(std::string phoneNumber) {
  this->_phoneNumber = phoneNumber;
  return (this->_phoneNumber);
}
