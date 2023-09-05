/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:31:27 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/04 15:53:24 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
  // Default test
  {
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    delete j;
    delete i;
  }

  // Array test
  {
    Animal *animals[10];

    for (int i = 0; i < 10; i++) {
      if (i % 2 == 0)
        animals[i] = new Dog();
      else
        animals[i] = new Cat();
    }

    for (int i = 0; i < 10; i++) {
      delete animals[i];
    }
  }

  // Shallow copy test
  {
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    const Animal *copyDog = j;
    const Animal *copyCat = i;

	(void)copyDog;
    (void)copyCat;

    delete j;
    delete i;
  }

  // Deep copt test
  {
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    const Animal *copyDog = new Dog(*(Dog *)j);
    const Animal *copyCat = new Cat(*(Cat *)i);

    delete j;
    delete i;
    delete copyDog;
    delete copyCat;
  }

  return (0);
}
