#include "Contact.hpp"
#include <iostream>

Contact::Contact(void) {
}

Contact::~Contact(void) {
}

std::string Contact::getFirstName(void) {
  return (this->firstName);
}

std::string Contact::getLastName(void) {
  return (this->lastName);
}

std::string Contact::getNickname(void) {
  return (this->nickname);
}

std::string Contact::getDarkestSecret(void) {
  return (this->darkestSecret);
}

std::string Contact::getPhoneNumber(void) {
  return (this->phoneNumber);
}

std::string Contact::setFirstName(std::string firstName) {
  this->firstName = firstName;
  return (this->firstName);
}

std::string Contact::setLastName(std::string lastName) {
  this->lastName = lastName;
  return (this->lastName);
}

std::string Contact::setNickname(std::string nickname) {
  this->nickname = nickname;
  return (this->nickname);
}

std::string Contact::setDarkestSecret(std::string darkestSecret) {
  this->darkestSecret = darkestSecret;
  return (this->darkestSecret);
}

std::string Contact::setPhoneNumber(std::string phoneNumber) {
  this->phoneNumber = phoneNumber;
  return (this->phoneNumber);
}
