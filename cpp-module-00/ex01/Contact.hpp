/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:12:44 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/25 23:17:27 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
 public:
  Contact(void);
  ~Contact(void);
  std::string getFirstName(void);
  std::string getLastName(void);
  std::string getNickname(void);
  std::string getDarkestSecret(void);
  std::string getPhoneNumber(void);
  std::string setFirstName(std::string firstName);
  std::string setLastName(std::string lastName);
  std::string setNickname(std::string nickname);
  std::string setDarkestSecret(std::string darkestSecret);
  std::string setPhoneNumber(std::string phoneNumber);

 private:
  std::string _firstName;
  std::string _lastName;
  std::string _nickname;
  std::string _darkestSecret;
  std::string _phoneNumber;
};

#endif  // CONTACT_HPP
