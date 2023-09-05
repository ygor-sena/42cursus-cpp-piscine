/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:31:27 by yde-goes          #+#    #+#             */
/*   Updated: 2023/09/04 16:13:55 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
  // Default test
  {
    const AAnimal *j = new Dog();
    const AAnimal *i = new Cat();

    delete j;
    delete i;
  }

  // Array test
  {
    AAnimal *animals[10];

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
    const AAnimal *j = new Dog();
    const AAnimal *i = new Cat();

    const AAnimal *copyDog = j;
    const AAnimal *copyCat = i;

    (void)copyDog;
    (void)copyCat;

    delete j;
    delete i;
  }

  // Deep copt test
  {
    const AAnimal *j = new Dog();
    const AAnimal *i = new Cat();

    const AAnimal *copyDog = new Dog(*(Dog *)j);
    const AAnimal *copyCat = new Cat(*(Cat *)i);

    delete j;
    delete i;
    delete copyDog;
    delete copyCat;
  }

  // This line doesn't work! Why?
  // Because the following virtual functions are pure within ‘AAnimal’:
  // virtual void AAnimal::makeSound() const; in class AAnimal
  /* {
    AAnimal *animal = new AAnimal();
    (void)animal;
  } */

  return (0);
}
