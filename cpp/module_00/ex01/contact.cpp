/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 05:00:45 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/03 08:33:49 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(){}

Contact::Contact
(
	std::string firstName,
	std::string lastName,
	std::string nickname,
	std::string phoneNumber,
	std::string darkestSecret
)
{
	firstName_ = firstName;
	lastName_ = lastName;
	nickname_ = nickname;
	phoneNumber_ = phoneNumber;
	darkestSecret_ = darkestSecret;
}

std::string Contact::getFirstName()
{
	return (firstName_);
}

std::string Contact::getLastName()
{
	return (lastName_);
}

std::string Contact::getNickname()
{
	return (nickname_);
}

std::string Contact::getPhoneNumber()
{
	return (phoneNumber_);
}

std::string Contact::getDarkestSecret()
{
	return (darkestSecret_);
}
