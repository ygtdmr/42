/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:32:54 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/03 08:33:54 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

# define CONTACT_NAME_MAX 10

class Contact
{
public:
	Contact();
	Contact
	(
	std::string	firstName,
	std::string	lastName,
	std::string	nickname,
	std::string	phoneNumber,
	std::string	darkestSecret
	);
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickname();
	std::string	getPhoneNumber();
	std::string	getDarkestSecret();
private:
	std::string	firstName_;
	std::string	lastName_;
	std::string	nickname_;
	std::string	phoneNumber_;
	std::string	darkestSecret_;
};

#endif
