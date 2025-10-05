/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:32:54 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/05 16:24:16 by yidemir          ###   ########.fr       */
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
	const std::string	&firstName,
	const std::string	&lastName,
	const std::string	&nickname,
	const std::string	&phoneNumber,
	const std::string	&darkestSecret
	);
	int		getLenArrContact() const;
	Contact	*getContact(int index);
private:
	int		indexArrContact_;
	int		lenArrContact_;
	Contact	arrContact_[PHONE_BOOK_CONTACT_MAX];
};

#endif
