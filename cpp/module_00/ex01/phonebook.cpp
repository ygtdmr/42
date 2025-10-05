/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 05:59:36 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/05 16:25:26 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	indexArrContact_ = 0;
	lenArrContact_ = 0;
}

void	PhoneBook::addContact
(
	const std::string	&firstName,
	const std::string	&lastName,
	const std::string	&nickname,
	const std::string	&phoneNumber,
	const std::string	&darkestSecret
)
{
	Contact contact(
		firstName,
		lastName,
		nickname,
		phoneNumber,
		darkestSecret
	);
	if (indexArrContact_ == PHONE_BOOK_CONTACT_MAX)
		indexArrContact_ = 0;
	arrContact_[indexArrContact_] = contact;
	indexArrContact_++;
	if (lenArrContact_ < PHONE_BOOK_CONTACT_MAX)
		lenArrContact_++;
}

int	PhoneBook::getLenArrContact() const
{
	return (lenArrContact_);
}

Contact	*PhoneBook::getContact(int index)
{
	if (index < lenArrContact_)
		return (arrContact_ + index);
	else
		return (0);
}
