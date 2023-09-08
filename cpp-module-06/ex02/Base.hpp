/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:17:19 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/07 18:43:32 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <exception>	
#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
 public:
  virtual ~Base();
};

// Inherited classes from Base
class A : public Base {};
class B : public Base {};
class C : public Base {};

// Full-access functions
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif  // BASE_HPP
