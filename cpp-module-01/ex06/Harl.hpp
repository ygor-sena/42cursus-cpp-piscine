/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:19:51 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/29 15:20:20 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
 public:
  Harl(void);
  ~Harl(void);
  void complain(std::string level);

 private:
  void _debug(void);
  void _info(void);
  void _warning(void);
  void _error(void);
};

#endif
