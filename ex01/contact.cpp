/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 05:00:45 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/06 06:32:33 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact( void ){}

Contact::Contact
(
	const std::string	&firstName,
	const std::string	&lastName,
	const std::string	&nickname,
	const std::string	&phoneNumber,
	const std::string	&darkestSecret
)
{
	firstName_ = firstName;
	lastName_ = lastName;
	nickname_ = nickname;
	phoneNumber_ = phoneNumber;
	darkestSecret_ = darkestSecret;
}

const std::string &Contact::getFirstName( void ) const
{
	return (firstName_);
}

const std::string &Contact::getLastName( void ) const
{
	return (lastName_);
}

const std::string &Contact::getNickname( void ) const
{
	return (nickname_);
}

const std::string &Contact::getPhoneNumber( void ) const
{
	return (phoneNumber_);
}

const std::string &Contact::getDarkestSecret( void ) const
{
	return (darkestSecret_);
}
