/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:42:01 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/02 16:39:15 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int	main( void )
{
	Data		myData;
	myData.id = 42;
	myData.name = "hello 42";
	myData.value = 42.42;

	Data		*originalPtr = &myData;
	std::cout << "--- serialization test ---" << std::endl;
	std::cout << "original pointer address: " << originalPtr << std::endl;
	std::cout << "original data content: " << std::endl;
	std::cout << "id: " << originalPtr->id << std::endl;
	std::cout << "name: " << originalPtr->name << std::endl;
	std::cout << "value: " << originalPtr->value << std::endl;
	std::cout << "--------------------------" << std::endl;

	uintptr_t	raw = Serializer::serialize(originalPtr);
	std::cout << "serialized value (uintptr_t): " << raw << std::endl;

	Data		*deserializedPtr = Serializer::deserialize(raw);
	std::cout << "deserialized pointer address: " << deserializedPtr << std::endl;
	std::cout << "--------------------------" << std::endl;

	std::cout << "deserialized data content: " << std::endl;
	std::cout << "id: " << deserializedPtr->id << std::endl;
	std::cout << "name: " << deserializedPtr->name << std::endl;
	std::cout << "value: " << deserializedPtr->value << std::endl;

	std::cout << "original pointer equals to deserialized pointer: ";
	std::cout << (originalPtr == deserializedPtr) << std::endl;

	return ( 0 );
}
