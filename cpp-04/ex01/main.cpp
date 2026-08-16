/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 04:57:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 15:49:02 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"


int main( void )
{
	std::cout << "----- Creating Animals -----" << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "----- Making Sounds -----" << std::endl;
	dog->makeSound();
	cat->makeSound();

	std::cout << "----- Deleting Animals -----" << std::endl;
	delete dog;
	delete cat;

	std::cout << "----- Creating Array of Animals -----" << std::endl;
	Animal* animals[4];
	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();

	std::cout << "----- Deleting Array of Animals -----" << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];

	std::cout << "----- Deep Copy Constructor Test -----" << std::endl;
	Dog dog1;
	Dog dog2 = dog1; // Copy constructor

	std::cout << "----- Deep Copy Assignment Test -----" << std::endl;
	Dog dog3;
	dog3 = dog1; // Copy assignment

	return 0;
}
