/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:42:01 by yidemir           #+#    #+#             */
/*   Updated: 2026/02/24 21:46:08 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int	main( void )
{
	Data	myData;
	myData.id = 42;
	myData.name = "Hello 42";
	myData.value = 42.42;

	Data	*originalPtr = &myData;
	std::cout << "--- Serialization Test ---" << std::endl;
	std::cout << "Original Pointer Address: " << originalPtr << std::endl;
	std::cout << "Original Data Content: " << std::endl;
	std::cout << "id: " << originalPtr->id << std::endl;
	std::cout << "name: " << originalPtr->name << std::endl;
	std::cout << "value: " << originalPtr->value << std::endl;
	std::cout << "--------------------------" << std::endl;

	uintptr_t raw = Serializer::serialize(originalPtr);
	std::cout << "Serialized Value (uintptr_t): " << raw << std::endl;

	Data* deserializedPtr = Serializer::deserialize(raw);
	std::cout << "Deserialized Pointer Address: " << deserializedPtr << std::endl;
	std::cout << "--------------------------" << std::endl;

	std::cout << "Deserialized Data Content: " << std::endl;
	std::cout << "id: " << deserializedPtr->id << std::endl;
	std::cout << "name: " << deserializedPtr->name << std::endl;
	std::cout << "value: " << deserializedPtr->value << std::endl;

	std::cout << "Original pointer equals to deserialized pointer: ";
	std::cout << (originalPtr == deserializedPtr) << std::endl;

	return ( 0 );
}
