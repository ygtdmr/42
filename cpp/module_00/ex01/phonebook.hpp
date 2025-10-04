/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:32:54 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/04 06:18:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "contact.hpp"

# define PHONE_BOOK_CONTACT_MAX 8

class PhoneBook
{
public:
	PhoneBook();
	void	addContact
	(
	std::string	firstName,
	std::string	lastName,
	std::string	nickname,
	std::string	phoneNumber,
	std::string	darkestSecret
	);
	int		getLenArrContact();
	Contact	*getArrContact();
private:
	int		indexArrContact_;
	int		lenArrContact_;
	Contact	arrContact[PHONE_BOOK_CONTACT_MAX];
};

#endif
