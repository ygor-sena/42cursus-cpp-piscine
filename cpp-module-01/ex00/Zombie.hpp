/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:53:05 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/28 14:29:49 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";

class Zombie {
 public:
  Zombie(std::string name);
  ~Zombie(void);
  void announce(void);

 private:
  std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif  // ZOMBIE_HPP